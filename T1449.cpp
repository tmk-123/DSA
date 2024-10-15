#include<iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;

        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        int current_sum = a[0], max_sum = a[0];

        for (int i = 1; i < n; i++){
            // nếu a[i] lớn hơn thì sẽ tính dãy con từ a[i] trở đi, còn không sẽ hợp nhất với dãy con liên tiếp trước đó
            current_sum = max(a[i], current_sum + a[i]);
            max_sum = max(max_sum, current_sum);
        }

        cout << max_sum << endl;
    }
}