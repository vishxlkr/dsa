#include <bits/stdc++.h>
using namespace std;
vector<long> useMinimumTokens(vector<int> warehouse, vector<vector<long>> catalog) {
    int n = warehouse.size();
    vector<long long> w(n);
    long long S=0;
    for(int i=0;i<n;i++){ w[i]=warehouse[i]; S+=w[i]; }
    sort(w.begin(), w.end());
    int q=catalog.size();
    vector<long> ans(q);
    for(int i=0;i<q;i++){
        long long a=catalog[i][0];
        long long b=catalog[i][1];
        long long best = LLONG_MAX;
        long long t2 = S - b;
        auto check = [&](int idx){
            if(idx<0||idx>=n) return;
            long long x = w[idx];
            long long cost1 = max(0LL, a - x);
            long long cost2 = max(0LL, b - (S - x));
            long long cost = cost1 + cost2;
            if(cost < best) best = cost;
        };
        int i1 = lower_bound(w.begin(), w.end(), a) - w.begin();
        int i2 = lower_bound(w.begin(), w.end(), t2) - w.begin();
        check(i1); check(i1-1); check(i2); check(i2-1);
        ans[i]=best;
    }
    return ans;
}




// Helper function to print the results
void print_results(const string& case_name, const vector<long>& results) {
    cout << case_name << " Output:" << endl;
    for (size_t i = 0; i < results.size(); ++i) {
        cout << results[i] << endl;
    }
    cout << endl;
}

int main() {
    // --- Sample Case 0 ---
    vector<int> warehouse0 = {5, 1, 1, 4};
    vector<vector<long>> catalog0 = {{5, 7}, {4, 10}, {7, 9}};
    vector<long> results0 = useMinimumTokens(warehouse0, catalog0);
    print_results("Sample Case 0", results0);

    // --- Sample Case 1 ---
    // Note: Based on the image, n=6 and the warehouse has 6 elements.
    vector<int> warehouse1 = {2, 4, 1, 4, 10, 7};
    vector<vector<long>> catalog1 = {{5, 22}, {14, 25}, {10, 10}};
    vector<long> results1 = useMinimumTokens(warehouse1, catalog1);
    print_results("Sample Case 1", results1);
    
    // Example from another provided image
    vector<int> warehouse2 = {2, 4, 1, 3};
    vector<vector<long>> catalog2 = {{5, 7}};
    vector<long> results2 = useMinimumTokens(warehouse2, catalog2);
    print_results("Second Example", results2);


    return 0;
}

