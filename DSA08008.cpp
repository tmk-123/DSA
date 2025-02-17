#include <iostream>
#include <queue>
using namespace std;

long long findBDN(int N) {
    queue<long long> q;
    q.push(1); 

    while (!q.empty()) {
        long long num = q.front();
        q.pop();

        if (num % N == 0) return num;  

        q.push(num * 10);       
        q.push(num * 10 + 1);  
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        cout << findBDN(N) << endl;
    }
}
