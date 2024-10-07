#include<iostream>
#include<vector>
#include<string>

using namespace std;

void permute(string &s, vector<bool> &used, string &current, vector<string> &result){
    if (current.size() == s.size()){
        result.push_back(current);
        return;
    }

    for (int i = 0; i < s.size(); i++){
        if (!used[i]){
            used[i] = true;
            current.push_back(s[i]);
            permute(s, used, current, result);
            current.pop_back(); // sau khi xong permute nghĩa là xong 1 hoán vị thì pop_back để for hết tìm xem còn kí tự nào khác 
            used[i] = false;
        }
    }
}

void solve(string &s){
    vector<string> result;
    vector<bool> used(s.size(), false);
    string current;

    permute(s, used, current, result);

    for (string x : result){
        cout << x << " ";
    }

    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        solve(s);
    }
    return 0;
}