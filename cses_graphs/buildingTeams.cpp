#include <bits/stdc++.h> 
using namespace std;

#define pb push_back
#define ll long long int
#define loop(i,a,b,c) for(i=a;i<b;i+=c)
#define endl "\n"

bool dfs(vector<vector<ll> >& adj, ll curr, vector<ll>& color){
    bool possible = true;
    for(ll i=0;i<adj[curr].size();i++){
        if(color[adj[curr][i]]==color[curr]){
            return false;
        }
        if(color[adj[curr][i]]==0){
            color[adj[curr][i]]=3-color[curr];
            possible = possible and dfs(adj,adj[curr][i],color);
        }
    }
    return possible;
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
    vector<ll> color(n+1,0);
    ll i;
    bool possible = true;
    for(i=1;i<=n;i++){
        if(color[i]==0){
            color[i] = 1;
            possible = possible and dfs(adj,i,color);
        }
    }
    if(possible){
        for(ll j=1;j<=n;j++){
            cout << color[j] << " ";
        }
        cout << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }
} 
