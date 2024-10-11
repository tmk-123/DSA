#include<iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n, k;
        cin >> n >> k;

        int a[k + 1];
        for (int i = 1; i <= k; i++) cin >> a[i];

        int index = k;

        while (a[index] == a[index - 1] + 1 && index >= 1){
            index--;
        }

     //   cout << index << " ";

        if (index == 1 && a[index] == 1){
            for (int i = 1; i <= k; i++){
                cout << n - k + i << " ";
            }
            
        }
        else{
            a[index]--;

            for (int i = 1; i <= index; i++){
                cout << a[i] << " ";
            }
            for (int i = index + 1; i <= k; i++){
                cout << n - k + i << " ";
            }
        }

        cout << endl;
    }
}