#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adjMatrix(n + 1, vector<int>(n + 1));
    vector<vector<int>> adjList(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> adjMatrix[i][j];
            if (adjMatrix[i][j]) adjList[i].push_back(j);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (auto& j : adjList[i]) cout << j << " ";
        cout << endl;
    }
}