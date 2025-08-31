#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <climits>

using namespace std;

vector<long> useMinimumTokens(vector<int> warehouse, vector<vector<long>> catalog) {
    vector<long> sorted_wh(warehouse.begin(), warehouse.end());
    sort(sorted_wh.begin(), sorted_wh.end());

    long total_cap = accumulate(sorted_wh.begin(), sorted_wh.end(), 0L);

    vector<long> results;
    results.reserve(catalog.size());

    for (const auto& shipment : catalog) {
        long req_cap = shipment[0];
        long back_cap = shipment[1];

        long A = req_cap;
        long B = total_cap - back_cap;

        long lower_ideal = min(A, B);
        long upper_ideal = max(A, B);

        auto it = lower_bound(sorted_wh.begin(), sorted_wh.end(), lower_ideal);

        if (it != sorted_wh.end() && *it <= upper_ideal) {
            results.push_back(max(0L, A - B));
        }
        else {
            long min_cost = LLONG_MAX;

            if (it != sorted_wh.end()) {
                long wh_above = *it;
                long cost_above = max(0L, A - wh_above) + max(0L, wh_above - B);
                min_cost = min(min_cost, cost_above);
            }

            if (it != sorted_wh.begin()) {
                long wh_below = *prev(it);
                long cost_below = max(0L, A - wh_below) + max(0L, wh_below - B);
                min_cost = min(min_cost, cost_below);
            }
            results.push_back(min_cost);
        }
    }

    return results;
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

