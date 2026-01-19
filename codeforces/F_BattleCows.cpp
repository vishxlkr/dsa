#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    int sz = 1 << n;
    
    vector<int>   a(sz);
    vector<int>   p(sz + 1, 0);



    for(int i = 0;   i < sz; i++) {
        cin >> a[i];
        p[i+1] = p[i] ^ a[i];
    }

    while(q--) {
        int idx, val;


        cin >> idx   >> val;



        idx--; 

        int diff =   a[idx] ^ val;
        int ans = 0;

        for(int h = 0;   h < n; h++) {
            int len = 1 << h;


            int me =   idx >> h;


            int op =    me ^ 1;

            int l1 =   me << h;

            int r1 = l1 + len - 1;


            int l2 =   op << h; 


            int r2 = l2 + len - 1;

            int s1 = (p[r1+1] ^ p[l1]) ^ diff;


            int s2 = (p[r2+1] ^ p[l2]);



            bool win = false;

            if (me < op) {
                if (s1 >= s2) win = true;


            } else {
                if (s1 > s2) win = true;
            }

            if (!win) ans += len;
        }
        cout << ans << "\n";

    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int t; 


    cin >> t;
    while(t--) {




        solve();


    }
    return 0;
}