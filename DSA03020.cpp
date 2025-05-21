#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        
        vector<int> v; // lưu vị trí các dấu "[", để tìm dấu "[" gần nhất nếu đang thiếu
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '[') v.push_back(i);
        }

        int cnt = 0; // số lượng ngoặc đóng - mở hiện tại
        int p = 0; // vị trí dấu ngoặc mở
        long long res = 0; 

        for (int i = 0; i < s.size(); i++) {   
            if (s[i] == '[') {
                cnt++;
                p++;
            }
            else {
                cnt--;
                if (cnt < 0) {
                    res += v[p] - i; // vì mỗi lần chỉ được swap 2 ký tự kề nhau nên phải swap lần lượt
                    swap(s[i], s[v[p]]);
                    p++;
                    cnt = 1; // chuyển đến dấu '[' tiếp theo nên cnt = 1
                }
            }
        }
        cout << res << endl;
    }
}