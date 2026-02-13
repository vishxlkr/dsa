#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to query the interactive judge
// Returns the path at index k (1-based)
// Returns empty vector if k is out of bounds
vector<int> query(long long k) {
    cout << "? " << k << endl;
    
    // Read response
    // If response is just 0 or -1, handle accordingly
    // Usually the format is: length v1 v2 ... vn
    // Or sometimes just the path on a line. 
    // Assuming standard interactive format: 
    // Input is usually "path_len v1 v2..." or just the line.
    // Based on typical problems of this type, we read the path.
    
    // Let's assume input format is a single line with path vertices separated by space.
    // If the judge outputs 0 or -1 first to indicate invalid/end, we check that.
    
    // NOTE: Specific input reading depends on the exact problem statement.
    // Here I implement a robust reader for standard interactive problems.
    
    // Read the whole line or first integer
    // Assuming the problem replies with the path directly.
    // If index is invalid, often returns 0 or empty line.
    
    // ADJUSTMENT for typical interactive problems:
    // Usually, you print "? k", and the judge replies.
    // If k is valid: "v1 v2 v3 ..."
    // If k is invalid: "0" or empty
    
    // Let's implement reading a line.
    string line;
    // We need to consume whitespace if any
    // In C++, cin >> val skips whitespace.
    
    // We'll try to read the first integer.
    // If the operation fails or it's a specific stop code, we handle it.
    
    // However, for this specific logic where we binary search bounds,
    // we need to distinguish "valid path" from "invalid index".
    // Usually, exceeding bounds returns specific indicator.
    
    // Let's assume the standard: 
    // If k > total_paths, it might return 0.
    
    // For this implementation, I will treat the input as:
    // "length v1 v2 ..." OR just "v1 v2 ..."
    // The previous python code used `int(input())` then map.
    // Let's assume the first number is the status or length.
    
    // Re-reading the Python provided:
    // q = int(input()) -> if q==0 return [] -> else read q integers.
    // This implies the first number is the LENGTH of the path.
    
    int len;
    if (!(cin >> len)) exit(0); // Safety exit
    
    if (len == -1) exit(0); // Judge indicates failure/exit
    if (len == 0) return {}; // Invalid index
    
    vector<int> path(len);
    for (int i = 0; i < len; ++i) {
        cin >> path[i];
    }
    return path;
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    // 1. Binary search for total number of paths
    long long lo = 1, hi = 1LL << 60; // 2^60 is safely large enough
    long long total_paths = 0;

    // To avoid infinite loops or massive queries if the upper bound is loose,
    // we rely on the judge returning 0 for out of bounds.
    
    // Find the largest index that returns a non-empty path
    // or smallest index that returns empty - 1.
    // Let's find the boundary.
    
    long long boundary_hi = hi; 
    
    // Optimization: Try to find a tighter upper bound if needed, 
    // but standard binary search is efficient enough (60 queries).
    
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        vector<int> res = query(mid);
        if (res.empty()) {
            hi = mid - 1;
        } else {
            total_paths = mid;
            lo = mid + 1;
        }
    }

    // 2. Determine the start index for each vertex block
    // start[v] is the index of the path [v]
    // The paths are sorted. 
    // Block for vertex v starts at the first index where path[0] >= v.
    
    vector<long long> start(n + 2);
    start[1] = 1;
    start[n + 1] = total_paths + 1; // Sentinel

    for (int v = 2; v <= n; ++v) {
        long long s_lo = start[v - 1];
        long long s_hi = total_paths + 1;
        long long ans = total_paths + 1;

        while (s_lo <= s_hi) {
            long long mid = s_lo + (s_hi - s_lo) / 2;
            if (mid > total_paths) {
                 // mid is out of bounds, so path[0] is effectively "infinity" >= v
                 // but we can't query it.
                 // We rely on the fact that we need the first valid path >= v
                 s_hi = mid - 1;
                 continue;
            }
            
            vector<int> res = query(mid);
            if (res.empty()) {
                // Should not happen if logic is correct and mid <= total_paths
                s_hi = mid - 1; 
            } else {
                if (res[0] >= v) {
                    ans = mid;
                    s_hi = mid - 1;
                } else {
                    s_lo = mid + 1;
                }
            }
        }
        start[v] = ans;
    }

    // 3. Calculate f[v]: number of paths starting with v
    vector<long long> f(n + 1);
    for (int v = 1; v <= n; ++v) {
        f[v] = start[v + 1] - start[v];
    }

    // 4. Identify Edges
    // For vertex v, paths start at start[v].
    // The first path is just [v].
    // The next path is [v, u1, ...].
    // There are f[u1] paths starting with v->u1.
    // Then the next is [v, u2, ...].
    
    vector<pair<int, int>> edges;
    for (int v = 1; v <= n; ++v) {
        long long remaining = f[v] - 1; // Subtract the single path [v]
        long long current_idx = start[v] + 1; // Start checking after [v]

        while (remaining > 0) {
            vector<int> res = query(current_idx);
            
            // Safety check
            if (res.size() < 2) {
                // This shouldn't happen in a valid DAG structure 
                // unless remaining > 0 logic is wrong.
                break; 
            }

            int u = res[1]; // The neighbor
            edges.push_back({v, u});

            // Skip all paths that go through u
            // The number of paths starting with v -> u is exactly f[u]
            long long skip = f[u];
            
            remaining -= skip;
            current_idx += skip;
        }
    }

    // Output result
    cout << "! " << edges.size() << endl;
    for (auto p : edges) {
        cout << p.first << " " << p.second << endl;
    }
}

int main() {
    // Usually interactive problems might have multiple test cases 
    // or just one. Assuming one based on typical flow, 
    // but if the input starts with T, uncomment below.
    
    /*
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    */
    
    // Assuming single test case based on provided Python snippet context,
    // but the python had 't = int(input())'. Let's match that.
    int t;
    if (cin >> t) {
        while(t--) {
            solve();
        }
    }
    
    return 0;
}git quickgit quickgit quickgit quickgit quickgit quickgit quickgit quickgit quickgit quick