

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    priority_queue<char, vector<char>, greater<char>> pq;
    unordered_map<char,int> mp;
    for (char c : s) {
        pq.push(c);
        mp[c]++;
    }

    for(auto ele:mp){
        if(ele.second > ((s.size()+1)/2)){
            cout<<"-1";
            return 0;
        }
    }

    string ans = "";



    while (!pq.empty()) {
        char curr = pq.top(); pq.pop();

        if(curr == ans.back() and  ans.size()!=0){
            
            char next = pq.top();
            pq.pop();
            ans = ans+next;
            pq.push(curr);
        } else {
            ans = ans + curr;
        }
    }

    cout << ans << endl;
    return 0;
}
