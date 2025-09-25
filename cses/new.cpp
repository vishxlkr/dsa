#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

long long modpow(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

long long nCr_mod(long long n, long long r) {
    if (r > n) return 0;
    static vector<long long> fact(1005, 1), invFact(1005, 1);
    static bool initialized = false;
    if (!initialized) {
        for (int i = 1; i <= 1000; i++) fact[i] = (fact[i-1] * i) % MOD;
        auto modInverse = [&](long long a) {
            return modpow(a, MOD - 2);
        };
        invFact[1000] = modInverse(fact[1000]);
        for (int i = 999; i >= 0; i--) invFact[i] = (invFact[i+1] * (i+1)) % MOD;
        initialized = true;
    }
    return (((fact[n] * invFact[r]) % MOD) * invFact[n-r]) % MOD;
}

int main() {
    int N;
    cin >> N;

    if (N == 0) {
        cout << 0 << endl;
        return 0;
    }

    long long total = (9 * modpow(10, N-1)) % MOD;
    long long no7 = 8 * modpow(9, N-1) % MOD;
    long long one7 = 0;

    for (int pos = 0; pos < N; pos++) {
        if (pos == 0) {
            one7 = (one7 + modpow(9, N-1)) % MOD;
        } else {
            long long ways = (8 * modpow(9, N-2)) % MOD;
            one7 = (one7 + ways) % MOD;
        }
    }

    long long valid = (total - no7 - one7 + 2*MOD) % MOD;
    cout << valid << endl;

    return 0;
}
