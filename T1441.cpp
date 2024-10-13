#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int s, p , n;

int isPrime(int n){
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

void backtracking(int curr, int number, int sum_curr, vector<int> &result, vector<vector<int>> &answer){
    if (number == 0 && sum_curr == s){
        answer.push_back(result);
        return;
    }

    for (int i = curr + 1; i <= s; i++){
        if (isPrime(i) && i + sum_curr <= s && number > 0){
            result.push_back(i);
            backtracking(i, number - 1, sum_curr + i, result, answer);
            result.pop_back();
        }
    }
}

int main(){
    int t;
    cin >> t;
    while (t--){
        cin >> n >> p >> s;

        vector<int> result;
        vector<vector<int>> answer;
        result.clear();
        answer.clear();

        backtracking(p, n, 0, result, answer);

        sort(answer.begin(), answer.end());
        cout << answer.size() << endl;
        for (auto ans : answer){
            for (int i = 0; i < ans.size(); i++){
                cout << ans[i];
                if (i < ans.size() - 1) cout << " ";
            }
            cout << endl;
        }
    }
}