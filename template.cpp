#include<bits/stdc++.h>
using namespace std;

#define ll          long long int
#define ld          long double
#define mod         1000000007
#define inf         1e18 // 10^18
#define endl        "\n"
#define pb          push_back
#define vi          vector<ll> 
#define vs          vector<string> 
#define pii         pair<ll,ll>
#define ump         unordered_map
#define mp          make_pair
#define pq_max      priority_queue<ll>
#define pq_min      priority_queue<ll, vi , greater<ll>>
#define all(n)      n.begin(), n.end()
#define ff          first
#define ss second 
#define mid(l,r)     (l+(r-l)/2);
#define bitc(n)     __buildin_popcount(n)
#define loop(i,a,b)     for(int i=(a);i<=(b);i++)
#define looprev(i,a,b)  for(int i=(a);i>=(b;i--))



#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); err(istream_iterator<string>(_s.begin()), args); }
#define logarr(arr,a,b) for(int z=(a);z<=(b);z++) cout<<(arr)[z]<<" "; cout<<endl;

template <typename T> T gcd(T a, T b){if(a%b) return gcd(b,a%b); return b;}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
vs tokenizer(string str,char ch){istringstream var((str)); vs v; string t; while(getline(var,t,ch)) v.push_back(t); return v;}

void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cout << *it << " = " << a << endl;
    err(++it, args...); 
}

// typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set_ll;
// typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> str_trie;







int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    

    return 0;
}

