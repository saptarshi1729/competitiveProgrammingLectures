#include <bits/stdc++.h> 
using namespace std;

#define pb push_back
#define ll long long int
#define loop(i,a,b,c) for(i=a;i<b;i+=c)
#define endl "\n"

void dfs(vector<vector<ll> >& adj, ll curr, vector<ll>& vis, ll par, vector<ll>& parent, ll &start, ll &prev, bool &cycleFound){
    vis[curr] = 1;
    parent[curr] = par;
    for(ll i=0;i<adj[curr].size();i++){
        ll v = adj[curr][i];
        if(v==par)
            continue;
        if(vis[v]){
            cycleFound = true;
            start = v;
            prev = curr;
            return;
        }
        dfs(adj,v,vis,curr,parent,start,prev,cycleFound);
        if(cycleFound)
            return;
    }
}

int main() 
{ 
    ll n, m;
    cin >> n;
    cin >> m;
    vector<vector<ll> > adj(n+1);
    for(ll i=0;i<m;i++){
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vector<ll> vis(n+1,0);
    vector<ll> parent(n+1,0);
    bool cycleFound = false;
    ll start = 0, prev = 0;
    for(ll i=1;i<=n;i++){
        if(!vis[i]){
            dfs(adj,i,vis,-1,parent,start,prev,cycleFound);
            if(cycleFound)
                break;
        }
    }
    if(!cycleFound){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        vector<ll> ans;
        ans.pb(start);
        ans.pb(prev);
        ll curr = prev;
        ll val = 2;
        while(curr!=start){
            curr = parent[curr];
            ans.pb(curr);
            val++;
        }
        cout << val << endl;
        for(ll i=0;i<ans.size();i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
} 
