#include<bits/stdc++.h>

using namespace std;

void solve(vector<int>& inDegree, vector<int>& outDegree) {
    for (int i = 1; i < inDegree.size(); i++) {
        if (inDegree[i] != outDegree[i]) {
            cout << "0\n";
            return;
        }
    }
    cout << "1\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> inDegree(V + 1, 0), outDegree(V + 1, 0);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            inDegree[v]++;
            outDegree[u]++;
        }

       solve(inDegree, outDegree);
    }
}