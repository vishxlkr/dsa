#include <bits/stdc++.h>
using namespace std;

int highestFloorReached(int input1, int input2, int input3[], int input4[])
{
    int N = input1;
    int M = input2;

    unordered_map<int, vector<int>> adj;

    for(int i=0;i<M;i++)
    {
        int a = input3[i];
        int b = input4[i];

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    unordered_set<int> vis;

    q.push(1);
    vis.insert(1);

    int ans = 1;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        ans = max(ans,node);

        for(int nxt : adj[node])
        {
            if(vis.count(nxt)==0)
            {
                vis.insert(nxt);
                q.push(nxt);
            }
        }
    }

    return ans;
}