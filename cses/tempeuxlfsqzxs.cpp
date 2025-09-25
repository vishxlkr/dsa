#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;

// fast modular exponentiation
long long modpow(long long base, long long exp, long long mod = MOD) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

long long countAtLeastTwoSevens(int N) {
    if (N < 2) return 0; // cannot have at least 2 sevens

    long long pow10_Nm1 = modpow(10, N - 1);
    long long pow9_N = modpow(9, N);
    long long pow9_Nm2 = (N >= 2) ? modpow(9, N - 2) : 1;

    long long term1 = (9LL * pow10_Nm1) % MOD;                 // 9 * 10^(N-1)
    long long term2 = pow9_N;                                  // 9^N
    long long term3 = (8LL * (N - 1)) % MOD * pow9_Nm2 % MOD;  // 8*(N-1)*9^(N-2)

    long long ans = (term1 - term2 - term3) % MOD;
    if (ans < 0) ans += MOD; 
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    cout << countAtLeastTwoSevens(N) << "\n";
    return 0;
}
