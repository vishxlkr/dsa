#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        cout << 2 << " " << 1;
        for(int i = 3; i <= n; i++){
            cout << " " << i;
        }
        cout << "\n";
    }
    return 0;
}
