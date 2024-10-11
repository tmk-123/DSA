#include <iostream>
#include <algorithm>

using namespace std;

int n, s, a[40];
int min_number = 100;

void Try(int sum, int cnt, int current){
    if (sum > s) return;

    if (sum == s){
        min_number = min(cnt, min_number);        
        return;
    }

    for (int i = current; i < n; i++){
        if (sum + a[i] <= s){
            Try(sum + a[i], cnt + 1, i + 1);
        }
    }
}

int main() {
    
    cin >> n >> s;

    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, greater<int>());
    
    Try(0, 0, 0);
    
    if (min_number != 100)
        cout << min_number;
    else cout << -1;

    return 0;
}
