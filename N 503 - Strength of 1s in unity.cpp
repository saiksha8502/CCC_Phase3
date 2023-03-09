#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;

int N, A[MAXN];

int MaxBinaryStringLen() {
    int maxLength = 0, currentLength = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] == 1) {
            currentLength++;
        } else {
            maxLength = max(maxLength, currentLength);
            currentLength = 0;
        }
    }
    maxLength = max(maxLength, currentLength);
    return maxLength;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    cout << MaxBinaryStringLen() << endl;
    
    return 0;
}
