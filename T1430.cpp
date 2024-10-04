#include<iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
		
        int n = s.length() - 1;
        int i = n;
        
        while (s[i] == '1' && i >= 0){
            s[i] = '0';
            i--;
        }
        
        if (i >= 0){
            s[i] = '1';
        }
        else{
            for (int j = 0; j < n; j++) s[j] = '0';
        }
        
        for (int j = 0; j <= n; j++){
            cout << s[j];
        }
        cout << endl;
    }
}