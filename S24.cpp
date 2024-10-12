#include<iostream>
#include<vector>

using namespace std;

int n, s;
int a[101];

int closestSum;

void Try(int index, int cnt, int currentSum){
    if (cnt == 3){
        if (currentSum <= s){
            closestSum = max(closestSum, currentSum);
        }
        return;
    }

    for (int i = index; i < n; i++){
        Try(i + 1, cnt + 1, currentSum + a[i]);
    }
}
int main(){
    int t;
    cin >> t;
    while (t--){
        cin >> n >> s;

        for (int i = 0; i < n; i++) cin >> a[i];

        closestSum = 0;
        Try(0, 0, 0);
        cout << closestSum << endl;
    }
}