#include<bits/stdc++.h>

using namespace std;

void merge(int a[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = a[left + i];
    for (int i = 0; i < n2; i++) R[i] = a[mid + 1 + i];

    // i, j chỉ số của n1, n2. k là chỉ số của array, k chạy từ left -> right
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] < R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
    }

    // chỉ còn 1 phần tử, while nốt
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}
void mergeSort(int a[], int left, int right) {
    // nếu có >= 2 phần tử 
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        
        mergeSort(a, 0, n - 1);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}