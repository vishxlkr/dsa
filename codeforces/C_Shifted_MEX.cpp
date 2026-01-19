#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return ;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    
    sort(a.begin() , a.end());

    a.erase(unique(a.begin(), a.end()), a.end());

    int max_mex = 0;

    int current_streak = 0;

    
    if (a.empty()) {
        cout << 0 << "\n";
        return;
    }

    max_mex = 1; 
    current_streak = 1;
    
    for (int i = 1; i < (int)a.size(); i++) {
       
        if (a[i] == a[i-1] + 1) {
            current_streak++;
        } else {
            current_streak = 1;
        }
        max_mex = max( max_mex,  current_streak);
    }

    cout << max_mex << "\n";
}

int main() {
   
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;



    while (t--) {
        solve();

    }


    
    return 0;
}