#include <bits/stdc++.h>
using namespace std;

int main() {

    int arr[] = {3, 5, 1, 5, 2, 5, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Convert array to vector for STL functions
    vector<int> v(arr, arr + n);

    // accumulate(start_iterator, end_iterator, initial_value)
    // initial_value = starting sum (0 means normal sum)
    int total = accumulate(v.begin(), v.end(), 0);
    cout << "Sum = " << total << endl;


    // count(start_iterator, end_iterator, value_to_count)
    int cnt = count(v.begin(), v.end(), 5);
    cout << "Count of value 5 = " << cnt << endl;


    // count_if(start_iterator, end_iterator, condition/lambda)
    // lambda must return true for elements you want to count
    int cnt_if = count_if(v.begin(), v.end(), [](int x){ return x > 3; });
    cout << "Count of elements > 3 = " << cnt_if << endl;


    // *max_element(start_iterator, end_iterator)
    // * -> dereference because function returns iterator
    int mx = *max_element(v.begin(), v.end());
    cout << "Maximum element = " << mx << endl;


    // *min_element(start_iterator, end_iterator)
    int mn = *min_element(v.begin(), v.end());
    cout << "Minimum element = " << mn << endl;


    // sort(start_iterator, end_iterator)
    sort(v.begin(), v.end());
    cout << "Sorted: ";
    for(int x : v) cout << x << " ";
    cout << endl;


    // reverse(start_iterator, end_iterator)
    reverse(v.begin(), v.end());
    cout << "Reversed: ";
    for(int x : v) cout << x << " ";
    cout << endl;


    // find(start_iterator, end_iterator, value_to_find)
    // returns iterator of first matching element
    auto it = find(v.begin(), v.end(), 2);
    if(it != v.end())
        cout << "Found 2 at index = " << (it - v.begin()) << endl;


    // binary_search(start_iterator, end_iterator, value)
    // NOTE: Works only if sorted
    sort(v.begin(), v.end());
    bool ok = binary_search(v.begin(), v.end(), 3);
    cout << "Binary search for 3 = " << (ok ? "Found" : "Not Found") << endl;


    // lower_bound(start_iterator, end_iterator, value)
    // returns first position where element >= value
    auto lb = lower_bound(v.begin(), v.end(), 3);
    cout << "Lower bound (>=3) index = " << (lb - v.begin()) << endl;


    // upper_bound(start_iterator, end_iterator, value)
    // returns first position where element > value
    auto ub = upper_bound(v.begin(), v.end(), 3);
    cout << "Upper bound (>3) index = " << (ub - v.begin()) << endl;


    // unique(start_iterator, end_iterator)
    // removes only consecutive duplicates
    auto newEnd = unique(v.begin(), v.end());
    cout << "After unique: ";
    for(int x : v) cout << x << " ";
    cout << endl;


    // iota(start_iterator, end_iterator, start_value)
    vector<int> v2(5);
    iota(v2.begin(), v2.end(), 1); // fills 1,2,3,4,5
    cout << "iota result: ";
    for(int x : v2) cout << x << " ";
    cout << endl;


    // partial_sum(src_begin, src_end, dest_begin)
    vector<int> pref(v2.size());
    partial_sum(v2.begin(), v2.end(), pref.begin());
    cout << "Prefix sum: ";
    for(int x : pref) cout << x << " ";
    cout << endl;


    // transform(src_begin, src_end, dest_begin, function)
    transform(v2.begin(), v2.end(), v2.begin(), [](int x){ return x * 2; });
    cout << "After transform (*2): ";
    for(int x : v2) cout << x << " ";
    cout << endl;

    return 0;
    
}