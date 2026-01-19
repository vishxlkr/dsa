#include <iostream>
#include <vector>

using namespace std;

#define ll long long

void solve() {



    int n, m;



    ll h;


    if (!(cin >> n >> m >> h)) return;

   
    vector<ll> orig(n + 1);

    vector<ll> current(n + 1);

    for (int i = 1; i <= n; i++) {


        cin >> orig[i];


        current[i] = orig[i];
    }

    vector<int> dirty_indices;

    vector<bool> is_dirty(n + 1, false);





    for (int  i = 0; i < m; i++) {
        int idx;
        ll  val;


        cin >> idx >> val;

  
        if (current[idx]  + val > h) {
           
            for (int pos :  dirty_indices) {
                current[pos]  = orig[pos];
                is_dirty[pos] = false;
            }
            dirty_indices.clear();
        } else {
            
            if  (!is_dirty[idx]) {
                is_dirty[idx] =  true;
                dirty_indices.push_back(idx);
            }
            current[idx]  += val;
        }
    }

   
    for (int i = 1; i  <= n; i++) {
        cout << current[i] <<  (i == n ? "" : " ");
    }
    cout <<  "\n";
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