#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int maze[10][10];
int n;
vector<string> paths;

// kiểm tra vị trí có hợp lệ hay không
bool isSafe(int x, int y, vector<vector<bool>> &visited){
    return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1 && !visited[x][y]);
}

void findPaths(int x, int y, vector<vector<bool>> &visited, string path){
    if (x == n - 1 && y == n - 1){
        paths.push_back(path);
        return;
    }

    visited[x][y] = true;

    if (isSafe(x + 1, y, visited)){
        findPaths(x + 1, y, visited, path + "D");
    }

    if (isSafe(x, y + 1, visited)){
        findPaths(x, y + 1, visited, path + "R");
    }

    if (isSafe(x - 1, y, visited)){
        findPaths(x - 1, y, visited, path + "U");
    }

    if (isSafe(x, y - 1, visited)){
        findPaths(x, y - 1, visited, path + "L");
    }

    visited[x][y] = false;
}
int main(){
    int t;
    cin >> t;
    while (t--){
        cin >> n;
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> maze[i][j];
            }
        }

        paths.clear();
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        if (maze[0][0] == 1){
            findPaths(0, 0, visited, "");
        }
        
        sort(paths.begin(), paths.end());

        if (paths.empty()){
            cout << -1 << endl;
        }
        else{
            for (auto path : paths){
                cout << path << " ";
            }
              cout << endl;
        }
    }
    return 0;
}