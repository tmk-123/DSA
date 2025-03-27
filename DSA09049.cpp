#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MAXN = 200005;

vector<int> tree[MAXN];
ll sum[MAXN];  // số lượng đơn vị dinh dưỡng nhận từ các con (tức là tổng số đơn vị cơ bản hay số node con)
ll val[MAXN];  // giá trị dinh dưỡng tại mỗi nút, 

void dfs(int u)
{
    for (int v : tree[u])
    {
        dfs(v);
        sum[u] += sum[v] + 1;   
        val[u] += val[v];       
    }
    val[u] += sum[u];  
}

int main()
{
    int n;
    cin >> n;

    for (int i = 2; i <= n; ++i)
    {
        int parent;
        cin >> parent;
        tree[parent].push_back(i);
    }

    for (int i = 1; i <= n; ++i)
    {
        val[i] = 1;  
        sum[i] = 0;
    }

    dfs(1);

    for (int i = 1; i <= n; ++i)
        cout << val[i] << ' ';
    cout << '\n';

    return 0;
}
