#include <bits/stdc++.h> 
using namespace std;

#define pb push_back
#define ll long long int
#define loop(i,a,b,c) for(i=a;i<b;i+=c)
#define endl "\n"

int main() 
{ 
    ll n, m, k;
    cin >> n;
    cin >> m >> k;
    ll INF = 1000000000000000;
    vector<vector<ll> > adj(n+1,vector<ll>(0));
    vector<vector<ll> > cost(n+1,vector<ll>(0));
    for(ll i=0;i<m;i++){
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].pb(b);
        cost[a].pb(c);
    }
    vector<vector<ll> > dist(n+1,vector<ll>(k,INF));
    multiset<pair<ll,ll> > s;
    s.insert(make_pair(0,1));
    dist[1][0] = 0;
    for(ll i=2;i<=n;i++){
        s.insert(make_pair(INF,i));
    }
    while(s.size()>0){
        ll v = s.begin()->second;
        ll cost1 = s.begin()->first;
        s.erase(s.begin());
        for(ll i=0;i<adj[v].size();i++){
            ll prevCost = dist[adj[v][i]][k-1];
            if(cost1+cost[v][i]<prevCost){
                pair<ll,ll> p = make_pair(prevCost,adj[v][i]);
                auto itr = s.find(p);
                if(itr!=s.end())
                    s.erase(itr);
                s.insert(make_pair(cost1+cost[v][i],adj[v][i]));
                dist[adj[v][i]][k-1] = cost1+cost[v][i];
                sort(dist[adj[v][i]].begin(),dist[adj[v][i]].end());
            }
        }
    }
    for(ll i=1;i<=k;i++){
        cout << dist[n][i-1] << " ";
    }
    cout << endl;
} 
