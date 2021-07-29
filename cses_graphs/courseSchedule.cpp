#include <bits/stdc++.h> 
using namespace std;

#define pb push_back
#define ll long long int
#define loop(i,a,b,c) for(i=a;i<b;i+=c)
#define endl "\n"

bool isCycle;

void dfs(ll curr, vector<vector<ll> >& adj, vector<ll>& vis, stack<ll>& v){
    vis[curr] = 1;
    for(ll y:adj[curr]){
        if(vis[y])
            continue;
        dfs(y,adj,vis,v);
    }
    v.push(curr);
}

void dfs1(ll curr, vector<vector<ll> >& adj, vector<ll>& vis){
    vis[curr] = 1;
    for(ll y:adj[curr]){
        if(!vis[y]){
            dfs1(y,adj,vis);
        }
        else if(vis[y]==2){
            continue;
        }
        else{
            isCycle = 1;
        }
        if(isCycle)
            return;
    }
    vis[curr] = 2;
}

bool doesCycleExist(ll n, vector<vector<ll> >& adj){
    isCycle = 0;
    vector<ll> vis(n+1,0);
    for(ll i=1;i<=n;i++){
        if(vis[i]==0){
            dfs1(i,adj,vis);
            if(isCycle)
                break;
        }
    }
    return isCycle;
}

int main(){
    ll n, m;
    cin >> n >> m;
    vector<vector<ll> > adj(n+1,vector<ll>());
    for(ll i=0;i<m;i++){
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }
    bool flag = doesCycleExist(n,adj);
    if(flag){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    stack<ll> v;
    vector<ll> vis(n+1,0);
    for(ll i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,adj,vis,v);
        }
    }
    while(v.size()>0){
        cout << v.top() << " ";
        v.pop();
    }
    cout << endl;
}