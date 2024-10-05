#include<iostream>

using namespace std;


int main(){
    int t;
    cin >> t;
    while (t--){
        int n, k;
        cin >> n >> k;

        int a[n + 1];

        for (int i = 1; i <= k; i++) a[i] = i;

        int ok = 1;
        

        while (ok){
            int index = k;
            for (int i = 1; i <= k; i++){
                cout << a[i];
            }
            cout << " ";

            while (a[index] == n - k + index && index >= 1){
                index--;
            }

            if (index == 0){
                ok = 0;
            }
            else{
                a[index]++;
                for (int i = index + 1; i <= k; i++){
                    a[i] = a[i - 1] + 1;
                }
            }
        }

        cout << endl;
    }
}