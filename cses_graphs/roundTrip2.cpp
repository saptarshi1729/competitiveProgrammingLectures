#include <bits/stdc++.h> 
using namespace std;

#define pb push_back
#define ll long long int
#define loop(i,a,b,c) for(i=a;i<b;i+=c)
#define endl "\n"

ll flag;

void dfs(ll curr, vector<vector<ll> >& adj, vector<ll>& vis, vector<ll>& prev){
    vis[curr] = 1;
    for(ll y:adj[curr]){
        if(!vis[y]){
            prev[y] = curr;
            dfs(y,adj,vis,prev);
        }
        else if(vis[y]==2){
            continue;
        }
        else{
            flag = y;
            prev[y] = curr;
        }
        if(flag)
            return;
    }
    vis[curr] = 2;
}

int main() 
{ 
    ll n, m, q;
    cin >> n;
    cin >> m;
    vector<vector<ll> > adj(n+1,vector<ll>());
    for(ll i=0;i<m;i++){
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }
    flag = 0;
    vector<ll> vis(n+1,0);
    vector<ll> prev(n+1,0);
    for(ll i=1;i<=n;i++){
        if(vis[i]==0){
            prev[i] = i;
            dfs(i,adj,vis,prev);
            if(flag)
                break;
        }
    }
    if(flag){
        vector<ll> path;
        path.pb(flag);
        ll curr = flag;
        while(prev[curr]!=flag){
            curr = prev[curr];
            path.pb(curr);
        }
        path.pb(flag);
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
