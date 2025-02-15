#include<bits/stdc++.h>

using namespace std;

int partition(int a[], int left, int right) {
    int pivot = a[right]; // chọn pivot bên phải
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[right]); // đưa pivot về đúng vị trí
    return i + 1;
}

void quickSort(int a[], int left, int right) {
    if (right <= left) return; // base case

    int pivot = partition(a, left, right);
    quickSort(a, left, pivot - 1);
    quickSort(a, pivot + 1, right);
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    quickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}