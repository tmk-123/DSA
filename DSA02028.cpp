#include <iostream>
#include <vector>
using namespace std;

int N, K, result = 0;
vector<int> A;

void backtrack(int index, int groupsLeft, int targetSum) {
    if (groupsLeft == 1) {
        // Nhóm cuối cùng, kiểm tra tổng còn lại
        int sum = 0;
        for (int i = index; i < N; i++)
            sum += A[i];
        if (sum == targetSum)
            result++;
        return;
    }

    int sum = 0; // mỗi khi quay lui thì chọn sum mới
    for (int i = index; i < N - groupsLeft + 1; i++) {
        sum += A[i];
        if (sum == targetSum) {
            // Tìm được 1 nhóm, tiếp tục cho nhóm tiếp theo
            backtrack(i + 1, groupsLeft - 1, targetSum);
        }
    }
}

int main() {
    cin >> N >> K;
    A.resize(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    int sumA = 0;
    for (int i = 0; i < N; i++)
        sumA += A[i];

    if (sumA % K != 0) {
        cout << 0 << endl;
        return 0;
    }

    int targetSum = sumA / K;
    backtrack(0, K, targetSum);
    cout << result << endl;

    return 0;
}
