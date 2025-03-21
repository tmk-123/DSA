#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> degree(V + 1, 0);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            degree[u]++;
            degree[v]++;
        }

        int odd_count = 0;
        for (int i = 1; i <= V; i++) {
            if (degree[i] % 2 == 1) odd_count++; 
        }

        if (odd_count == 0) cout << "2\n";
        else if (odd_count == 2) cout << "1\n";
        else cout << "0\n";
    }
}