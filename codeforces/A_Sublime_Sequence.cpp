#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int x, w;
        cin >> x >> w;
        if(w % 2 == 0) cout << 0 << "\n";
        else cout << x << "\n";
    }
    return 0;
}
