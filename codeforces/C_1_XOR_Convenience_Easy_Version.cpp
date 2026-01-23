#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    long long n, target_x;
    cin >> n >> target_x;

    long long initial_reach = 0;
    long long best_cycle_progress = -2e18; // Start with a very low number

    for (int i = 0; i < n; i++) {
        long long a, b, c;
        cin >> a >> b >> c;

      
        long long free_jumps = b - 1;
        initial_reach += free_jumps * a;

        // Step 2: Calculate the net progress of a full cycle
        // A cycle consists of 1 rollback + b forward jumps (the cursed one + the next batch of free ones).
        // Effectively, every time we accept 1 rollback, we gain:
        // (1 * a - c) [the cursed jump] + ((b - 1) * a) [the next batch of free jumps]
        // This simplifies to: (a * b) - c
        long long cycle_progress = (a * b) - c;

        if (cycle_progress > best_cycle_progress) {
            best_cycle_progress = cycle_progress;
        }
    }

    // If we can reach the target just using free jumps (0 rollbacks)
    if (initial_reach >= target_x) {
        cout << 0 << endl;
        return;
    }

    // If we still have distance to cover
    long long remaining_dist = target_x - initial_reach;

    // If our best cycle doesn't actually move us forward (or moves us backward),
    // and we haven't reached the target yet, it's impossible.
    if (best_cycle_progress <= 0) {
        cout << -1 << endl;
    } else {
        ision: (numerator + denominator - 1) / denominator
        long long rollbacks_needed = (remaining_dist + best_cycle_progress - 1) / best_cycle_progress;
        cout << rollbacks_needed << endl;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}