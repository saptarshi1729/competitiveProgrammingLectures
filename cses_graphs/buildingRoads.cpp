#include <bits/stdc++.h> 
using namespace std;

#define pb push_back
#define ll long long int
#define loop(i,a,b,c) for(i=a;i<b;i+=c)
#define endl "\n"

void dfs(vector<vector<ll> >& adj, ll curr, vector<ll>& vis){
    if(vis[curr]==1)
        return;
    vis[curr] = 1;
    for(ll i=0;i<adj[curr].size();i++){
        dfs(adj,adj[curr][i],vis);
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
    vector<ll> comp;
    for(ll i=1;i<=n;i++){
        if(vis[i]==0){
            comp.pb(i);
            dfs(adj,i,vis);
        }
    }
    cout << comp.size() - 1 << endl;
    for(ll i=1;i<comp.size();i++){
        cout << comp[i-1] << " " << comp[i] << endl;
    }
} 
