#include<iostream>
#include<vector>

using namespace std;

void print(vector<int> &partitions){
    cout << "(";

    for (int i = 0; i < partitions.size(); i++){
        if (i > 0) cout << " ";
        cout << partitions[i];
    }

    cout << ")";
}

void findPartitions(int n, int max_current, vector<int>& current_partition){
    if (n == 0){
        print(current_partition);
        cout << " ";
        return;
    }

    for (int i = max_current; i > 0; i--){
        if (i <= n){
            current_partition.push_back(i);
            findPartitions(n - i, i, current_partition); // i de khong lap hoan vi
            current_partition.pop_back(); // xoa tu vua them de quay lui
        }
    }
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> partition;
        findPartitions(n, n, partition);
        cout << endl;  
    }
    return 0;
}