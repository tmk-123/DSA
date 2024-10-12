#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int n; // Số thành phố
vector<vector<int>> C; // Ma trận chi phí
int minCost = INT_MAX; // Chi phí tối thiểu

// Hàm tính chi phí cho một hoán vị
void backtrack(vector<int>& path, int pos, int cost) {
    // Nếu đã thăm tất cả các thành phố
    if (pos == n) {
        // Quay lại thành phố đầu tiên
        cost += C[path[pos - 1]][0];
        minCost = min(minCost, cost);
        return;
    }

    // Thử tất cả các thành phố chưa được thăm
    for (int city = 1; city < n; city++) {
        // Nếu thành phố city chưa được thăm
        if (find(path.begin(), path.end(), city) == path.end()) {
            path.push_back(city);
            backtrack(path, pos + 1, cost + C[path[pos - 1]][city]);
            path.pop_back(); // Quay lại để thử hoán vị khác
        }
    }
}

int main() {
    // Nhập số thành phố
    cin >> n;
    
    // Khởi tạo ma trận chi phí
    C.resize(n, vector<int>(n));
    
    // Nhập dữ liệu cho ma trận chi phí
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> C[i][j];
        }
    }

    // Khởi tạo đường đi, bắt đầu từ thành phố 0
    vector<int> path;
    path.push_back(0); // Bắt đầu từ thành phố 0

    // Gọi hàm quay lui
    backtrack(path, 1, 0);

    // In ra chi phí tối thiểu
    cout << minCost << endl;

    return 0;
}
