#include<bits/stdc++.h>

using namespace std;

void Try(char from, char to, char aux, int n) {  
    if (n == 1) {
        cout << from << " -> " << to << endl;
        return;
    }
    
    // n - 1 cái từ nguồn sang phần phụ
    Try(from, aux, to, n - 1);

    // 1 cái còn lại từ nguồn đến đích
    cout << from << " -> " << to << endl;

    // n - 1 cái từ phụ sang đích
    Try(aux, to, from, n - 1);
}
int main() {
    int n;
    cin >> n;
    Try('A', 'C', 'B', n);
}