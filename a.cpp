#include <cerrno>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <chrono>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#ifndef HEARTBEAT_BUILD_ID
#define HEARTBEAT_BUILD_ID <undefined>
#endif
#define STRINGIFY_DETAIL(x) #x
#define STRINGIFY(x) STRINGIFY_DETAIL(x)

using namespace std::chrono;

class HeartBeatServer {
 public:
  explicit HeartBeatServer(int port)
  : m_tbeg { system_clock::now() },
    m_fd{::socket(AF_INET, SOCK_STREAM, 0) }
  {
    if (m_fd < 0) {
      throw std::runtime_error("cannot create socket");
    }
    
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    
    int opt = 1;
    ::setsockopt(m_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    
    if (auto err = ::bind(m_fd, (struct sockaddr*)(&server), sizeof(server));
        err < 0) {
      throw std::runtime_error("cannot bind socket");
    }

    if (auto err = ::listen(m_fd, 64); err < 0) {
      throw std::runtime_error("cannot start listening");
    }
  }

  void serve() {
    while (true) {
      struct sockaddr_in client;
      socklen_t client_len = sizeof(client);
      const auto cfd = ::accept(m_fd, (struct sockaddr*)(&client), &client_len);
      if (cfd < 0) {
        throw std::runtime_error("cannot create new client connection");
      }
      const auto response = status();
      if (auto status = ::send(cfd, response.c_str(), response.size(), 0);
          status < 0) {
        throw std::runtime_error("cannot send response to client");
      }
      ::shutdown(cfd, SHUT_RDWR);
      ::close(cfd);
    }
  }
  
 private:
  std::string status() const {
    const auto uptime = system_clock::now() - m_tbeg;
    std::ostringstream oss;
    oss << "{\"status\":\"ok\",\"uptime\":"
        << duration_cast<seconds>(uptime).count()
        << ",\"build\":\"" <<  STRINGIFY(HEARTBEAT_BUILD_ID) << "\"}";
    return oss.str();
  }
 private:
  const system_clock::time_point m_tbeg;
  const int m_fd;
};

int main() {
  HeartBeatServer server(8081);
  server.serve();
}