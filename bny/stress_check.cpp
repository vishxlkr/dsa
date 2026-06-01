#include <bits/stdc++.h>
using namespace std;

string circularCircuit_under_test(const string& input1) {
    int n = (int)input1.size();
    vector<string> answers;

    for (int first = 0; first <= 1; first++) {
        for (int second = 0; second <= 1; second++) {
            vector<int> p(n);

            p[0] = first;
            if (n > 1) p[1] = second;

            for (int i = 1; i < n - 1; i++) {
                int s = input1[i] - '0';
                p[i + 1] = s ^ p[i] ^ p[i - 1];
            }

            bool valid = true;

            if (n > 1) {
                if ((p[n - 2] ^ p[n - 1] ^ p[0]) != (input1[n - 1] - '0'))
                    valid = false;

                if ((p[n - 1] ^ p[0] ^ p[1]) != (input1[0] - '0'))
                    valid = false;
            } else {
                if ((p[0] ^ p[0] ^ p[0]) != (input1[0] - '0'))
                    valid = false;
            }

            if (valid) {
                string prev = "";
                for (int x : p) prev += char(x + '0');
                answers.push_back(prev);
            }
        }
    }

    if (answers.empty()) return "No Chance";
    if ((int)answers.size() > 1) return "Multiple Scenario";
    return answers[0];
}

string brute_oracle(const string& s) {
    int n = (int)s.size();
    vector<string> ans;

    for (int mask = 0; mask < (1 << n); mask++) {
        string p(n, '0');
        for (int i = 0; i < n; i++) {
            p[i] = ((mask >> i) & 1) + '0';
        }

        bool ok = true;
        for (int i = 0; i < n; i++) {
            int left = p[(i - 1 + n) % n] - '0';
            int cur = p[i] - '0';
            int right = p[(i + 1) % n] - '0';
            int v = left ^ cur ^ right;
            if (v != s[i] - '0') {
                ok = false;
                break;
            }
        }
        if (ok) ans.push_back(p);
    }

    if (ans.empty()) return "No Chance";
    if ((int)ans.size() > 1) return "Multiple Scenario";
    return ans[0];
}

string random_binary(mt19937& rng, int n) {
    string s;
    s.reserve(n);
    for (int i = 0; i < n; i++) s.push_back(char('0' + (rng() & 1)));
    return s;
}

int main() {
    mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

    // Exhaustive check for smaller n.
    for (int n = 1; n <= 14; n++) {
        int total = 1 << n;
        for (int mask = 0; mask < total; mask++) {
            string s(n, '0');
            for (int i = 0; i < n; i++) s[i] = char('0' + ((mask >> i) & 1));

            string got = circularCircuit_under_test(s);
            string exp = brute_oracle(s);
            if (got != exp) {
                cout << "Mismatch in exhaustive test\n";
                cout << "n=" << n << " s=" << s << "\n";
                cout << "got=" << got << " exp=" << exp << "\n";
                return 1;
            }
        }
    }

    // Additional random stress for larger n.
    const int RANDOM_TESTS = 3000;
    uniform_int_distribution<int> distN(1, 16);

    for (int tc = 1; tc <= RANDOM_TESTS; tc++) {
        int n = distN(rng);
        string s = random_binary(rng, n);
        string got = circularCircuit_under_test(s);
        string exp = brute_oracle(s);

        if (got != exp) {
            cout << "Mismatch in random test\n";
            cout << "tc=" << tc << " n=" << n << " s=" << s << "\n";
            cout << "got=" << got << " exp=" << exp << "\n";
            return 1;
        }
    }

    cout << "All stress tests passed.\n";
    return 0;
}
