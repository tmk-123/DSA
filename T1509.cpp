#include<iostream>
#include<cstring>
#include<climits>

using namespace std;

int n, visited[20] = {1}, min_cost = INT_MAX, c[20][20]; // người đầu tiên đã đi nên bằng 1, còn lại bằng 0

void travelling_salesman_problem(int city, int count, int cost){
    if (cost > min_cost) return;

    if (count == n && c[city][0] > 0){
        min_cost = min(min_cost, cost + c[city][0]);
        return;
    }

    for (int i = 0; i < n; i++){
        // c[city][i] > 0 để loại bỏ trường hợp đi về điểm xuất phát
        if (!visited[i] && c[city][i] > 0){ 
            visited[i] = 1;
            travelling_salesman_problem(i, count + 1, cost + c[city][i]);
            visited[i] = 0;
        }
    }
}
int main(){
    cin >> n;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> c[i][j];
        }
    }
    
    travelling_salesman_problem(0, 1, 0);
    cout << min_cost;
}   