#include<iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int a[n + 1];
        for (int i = 1; i <= n; i++) cin >> a[i];

        int index = n;

        while (a[index] < a[index - 1] && index >= 1){
            index--;
        }

        if (index == 0){
            for (int i = 1; i <= n; i++){
                cout << i << " ";
            }
        }
        else{
            swap(a[index], a[index - 1]);

            int left = index, right = n;
            while (left < right){
                swap(a[left], a[right]);
                left++;
                right--;
            }

            for (int i = 1; i <= n; i++){
            cout << a[i] << " ";
            }
        }

        cout << endl;
    }
}