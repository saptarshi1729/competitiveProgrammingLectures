#include <bits/stdc++.h> 
using namespace std;

#define pb push_back
#define ll long long int
#define loop(i,a,b,c) for(i=a;i<b;i+=c)
#define endl "\n"

void bfs(ll start, ll end, vector<vector<ll> >& adj, vector<ll>& vis){
    vector<ll> way;
    way.pb(start);
    vis[start] = 1;
    vector<ll> prev;
    prev.pb(-1);
    for(ll i=0;i<way.size();i++){
        for(ll j=0;j<adj[way[i]].size();j++){
            ll v = adj[way[i]][j];
            if(vis[v]==1)
                continue;
            vis[v] = 1;
            prev.pb(i);
            way.pb(v);
            if(v==end)
                break;
        }
        if(vis[end])
            break;
    }
    if(vis[end]){
        vector<ll> path;
        ll curr = way.size()-1;
        while(curr!=-1){
            path.pb(way[curr]);
            curr = prev[curr];
        }
        cout << path.size() << endl;
        for(ll i=path.size()-1;i>=0;i--){
            cout << path[i] << " ";
        }
        cout << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
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
    vector<ll> path;
    bfs(1,n,adj,vis);
} 
