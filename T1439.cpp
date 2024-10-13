#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int n, k, ok;
int a[100];

void print(vector<int> &result){
    for (int i = 0; i < result.size(); i++){
        cout << result[i];
        if (i < result.size() - 1) cout << " ";
    }
}

void backtracking(int sum, int current, vector<int> &result){
    if (sum == k){
        cout << "[";
        print(result);
        cout << "]";
        ok = 1;
        return;
    }

    for (int i = current; i < n; i++){
        if (a[i] >= current, sum + a[i] <= k) {
            result.push_back(a[i]);
            backtracking(sum + a[i], i, result);
            result.pop_back();
        }
    }
}
int main(){
    int t;
    cin >> t;
    while (t--){
        cin >> n >> k;

        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a, a + n);
        vector<int> result;
        ok = 0;

        backtracking(0, 0, result);

        if (!ok) cout << -1;
        cout << endl;
    }
}