#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Hàm đếm số lần xuất hiện của từng chữ số (Counting Sort)
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0}; // Chỉ có 10 chữ số (0-9)

    // Đếm số lượng chữ số ở vị trí hiện tại (exp)
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Cập nhật count[i] để biết vị trí chính xác của từng phần tử
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = 0; i < 10; i++) cout << count[i] << " ";
    cout << endl;
    // Sắp xếp lại mảng theo chữ số hiện tại
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Sao chép mảng đã sắp xếp vào arr[]
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
    
    
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

// Hàm Radix Sort
void radixSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end()); // Tìm giá trị lớn nhất

    // Thực hiện Counting Sort cho từng chữ số từ hàng đơn vị, chục, trăm...
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSort(arr, exp);
}

// Hàm main để kiểm tra
int main() {
    vector<int> arr = {21, 300, 8, 92, 654, 100, 252, 333, 693, 18};

    cout << "Mảng trước khi sắp xếp: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    radixSort(arr);

    cout << "Mảng sau khi sắp xếp: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
