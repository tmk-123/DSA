#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

string s;
int n;

void Try(int index, string current, vector<string> &res){
    if (index == s.length()){
        if (!current.empty()){
            res.push_back(current);
        }
        return;
    }

    Try(index + 1, current, res); // không chọn ký tự tại vị trí index

    Try(index + 1, current + s[index], res);  // chọn ký tự tại vị trí index
}
int main(){
    int t;
    cin >> t;
    while (t--){
        cin >> n;
        cin >> s;
        vector<string> res;

        Try(0, "", res);
        sort(res.begin(), res.end());

        for (string subset : res){
            cout << subset << " "; 
        }
        cout << endl;   
    }
}