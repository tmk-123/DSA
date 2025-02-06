#include<bits/stdc++.h>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    for (char &c : a) {
        if (c == '6') c = '5';
    }
    for (char &c : b) {
        if (c == '6') c = '5';
    }
    int minVal = stoi(a) + stoi(b);

    for (char &c : a) {
        if (c == '5') c = '6';
    }
    for (char &c : b) {
        if (c == '5') c = '6';
    }
    int maxVal = stoi(a) + stoi(b);
    
    cout << minVal << " " << maxVal;
}