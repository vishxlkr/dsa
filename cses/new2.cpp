#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    long long totalCost = 0;

    // First strike on tier 1 is free, so cost = 0
    // After finishing tier i, recharge cost becomes Bi
    for (int i = 0; i < N; i++) {
        long long cost = A[i] * (i == 0 ? 0 : B[i-1]);
        totalCost += cost;
    }

    cout << totalCost << "\n";
    return 0;
}
