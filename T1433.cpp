#include<iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
		
        int n = s.length();
        int index = n - 1;
        
        while (s[index] == '0' && index >= 0){
            s[index] = '1';
            index--;
        }

        if (index < 0){
            for (int i = 0; i < n; i++){
                cout << 1;
            }
        }
        else{
            s[index] = '0';
            for (int i = 0; i < n; i++){
                cout << s[i];
            }
        }

        cout << endl;
    }
}