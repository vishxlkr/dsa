#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;




void solve() {
    int n, m,  k;


    if (!(cin  >> n >>  m >>  k)) return;


    vector<int> a(n);
    for (int i = 0; i <  n; i++) cin >> a[i];

    vector<int> b(m);
    for (int i =  0; i < m; i++) cin >> b[i];

    string s;

    cin >>  s;

   
    sort(b.begin(),  b.end());

     
    vector<int> mn(k + 1, 0),  mx(k + 1, 0);
    int cur = 0;
    
    for (int i = 0; i < k; i++) {
        if (s[i] == 'L') cur--;
        else cur++;
        
        mn[i + 1] =  min(mn[i], cur);
        mx[i + 1] =    max(mx[i], cur);
    }

   
    vector<int> deaths(k  + 2, 0);

 
    for (int i = 0; i < n;  i++) {

        int start_pos = a[i];


        int low = 1, high = k;


        int die_time = -1;



        while (low <= high) {


            int mid = low + (high - low) / 2;

            
            long long left_bound = (long long)start_pos + mn[mid];


            long long right_bound = (long long)start_pos + mx[mid];

          


            auto it = lower_bound(b.begin(), b.end(), left_bound);

            
            if (it != b.end() && *it <= right_bound) {
                die_time = mid;
                high = mid - 1; 
                
            } else {
                low = mid + 1;
            }
        }

        if (die_time != -1) {
            deaths[die_time]++;
        }
    }

    // Output the number of survivors at each step
    int current_survivors = n;
    for (int i = 1; i <= k; i++) {
        current_survivors -= deaths[i];
        cout << current_survivors << (i == k ? "" : " ");
    }
    cout << "\n";
}

int main() {
   
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}