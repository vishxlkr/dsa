#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        // dp[bit][state_p][state_q] = minimum cost
        // state: 0 = EQUAL, 1 = LESS, 2 = MORE
        vector<vector<vector<long long>>> dp(32, vector<vector<long long>>(3, vector<long long>(3, INF)));
        vector<vector<vector<pair<pair<int,int>, pair<int,int>>>>> parent(32);
        
        for (int i = 0; i < 32; i++) {
            parent[i].resize(3, vector<pair<pair<int,int>, pair<int,int>>>(3));
        }
        
        // Base case: start from MSB with EQUAL state
        dp[31][0][0] = 0;
        
        // Valid bit pairs: (0,0), (0,1), (1,0) - these satisfy p_bit & q_bit = 0
        vector<pair<int,int>> valid = {{0,0}, {0,1}, {1,0}};
        
        // Process from MSB to LSB
        for (int bit = 30; bit >= 0; bit--) {
            int x_bit = (x >> bit) & 1;
            int y_bit = (y >> bit) & 1;
            long long weight = (1LL << bit);
            
            // Try all current states
            for (int sp = 0; sp < 3; sp++) {
                for (int sq = 0; sq < 3; sq++) {
                    if (dp[bit + 1][sp][sq] >= INF) continue;
                    
                    long long cur_cost = dp[bit + 1][sp][sq];
                    
                    // Try all valid bit pairs
                    for (auto [p_bit, q_bit] : valid) {
                        // Compute next state for p
                        int next_sp = sp;
                        if (sp == 0) { // Currently equal
                            if (p_bit < x_bit) next_sp = 1; // becomes less
                            else if (p_bit > x_bit) next_sp = 2; // becomes more
                        }
                        
                        // Compute next state for q
                        int next_sq = sq;
                        if (sq == 0) { // Currently equal
                            if (q_bit < y_bit) next_sq = 1; // becomes less
                            else if (q_bit > y_bit) next_sq = 2; // becomes more
                        }
                        
                        // Calculate cost contribution for this bit
                        long long cost_p = 0, cost_q = 0;
                        
                        if (next_sp == 1) { // p < x
                            cost_p = (x_bit - p_bit) * weight;
                        } else if (next_sp == 2) { // p > x
                            cost_p = (p_bit - x_bit) * weight;
                        }
                        
                        if (next_sq == 1) { // q < y
                            cost_q = (y_bit - q_bit) * weight;
                        } else if (next_sq == 2) { // q > y
                            cost_q = (q_bit - y_bit) * weight;
                        }
                        
                        long long new_cost = cur_cost + cost_p + cost_q;
                        
                        // Update DP if better (use <= to allow updates with same cost)
                        if (new_cost <= dp[bit][next_sp][next_sq]) {
                            dp[bit][next_sp][next_sq] = new_cost;
                            parent[bit][next_sp][next_sq] = {{sp, sq}, {p_bit, q_bit}};
                        }
                    }
                }
            }
        }
        
        // Find minimum cost final state
        // Prefer certain states when costs are equal
        long long min_cost = INF;
        int final_sp = -1, final_sq = -1;
        
        for (int sp = 0; sp < 3; sp++) {
            for (int sq = 0; sq < 3; sq++) {
                if (dp[0][sp][sq] < min_cost) {
                    min_cost = dp[0][sp][sq];
                    final_sp = sp;
                    final_sq = sq;
                }
            }
        }
        
        // Reconstruct the answer
        long long p = 0, q = 0;
        int cur_sp = final_sp, cur_sq = final_sq;
        
        for (int bit = 0; bit <= 30; bit++) {
            auto [prev_states, bits] = parent[bit][cur_sp][cur_sq];
            auto [prev_sp, prev_sq] = prev_states;
            auto [p_bit, q_bit] = bits;
            
            if (p_bit) p |= (1LL << bit);
            if (q_bit) q |= (1LL << bit);
            
            cur_sp = prev_sp;
            cur_sq = prev_sq;
        }
        
        cout << p << " " << q << "\n";
    }
    
    return 0;
}

git quickgit quickgit quickgigit quickgit quickgit quickgit quickgit quickgit quickgit quickgit quick