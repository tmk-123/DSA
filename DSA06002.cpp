#include<bits/stdc++.h>

using namespace std;


struct Value {
    int a, b, index;
};

bool compare(Value x, Value y) {
    if (x.b == y.b) return x.index < y.index;
    return x.b < y.b;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<Value> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i].a;
            v[i].b = abs(v[i].a - x);
            v[i].index = i;
        }

        sort(v.begin(), v.end(), compare);
        for (int i = 0; i < n; i++) {
            cout << v[i].a << " ";
        }
        cout << endl;
    }
}