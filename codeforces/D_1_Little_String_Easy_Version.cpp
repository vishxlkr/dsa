#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;
const int MAXN = 200000;

ll fact[MAXN+1], pw2[MAXN+1];

map<ll,ll> factorize(ll x){
    map<ll,ll> f;
    for(ll p=2;p*p<=x;p++){
        while(x%p==0){
            f[p]++;
            x/=p;
        }
    }
    if(x>1) f[x]++;
    return f;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    fact[0]=1;
    for(int i=1;i<=MAXN;i++) fact[i]=fact[i-1]*i%MOD;
    pw2[0]=1;
    for(int i=1;i<=MAXN;i++) pw2[i]=pw2[i-1]*2%MOD;

    int t;
    cin>>t;
    while(t--){
        int n;
        ll c;
        cin>>n>>c;
        string s;
        cin>>s;

        int ones=0, zeros=0;
        for(int i=1;i<n;i++){
            if(s[i]=='1') ones++;
            else zeros++;
        }

        // compute f modulo
        ll fmod = pw2[ones] * fact[zeros] % MOD;

        // check divisibility
        auto fc = factorize(c);

        bool ok = true;
        for(auto [p,need]:fc){
            ll have = 0;

            if(p==2){
                have += ones;
            }

            ll z = zeros;
            while(z){
                z/=p;
                have+=z;
            }

            if(have < need){
                ok=false;
                break;
            }
        }

        if(ok) cout<<-1<<"\n";
        else cout<<fmod<<"\n";
    }
}



git quickgit quickgit quickgit quickgit quickgitgit quick
 quickgit quickgit quickgit quick