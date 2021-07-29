#include <bits/stdc++.h> 
using namespace std;

#define pb push_back
#define ll long long int
#define loop(i,a,b,c) for(i=a;i<b;i+=c)
#define endl "\n"

int main() 
{ 
    ll n, m;
    cin >> n;
    cin >> m;
    vector<vector<ll> > adj(n+1,vector<ll>(0));
    vector<vector<ll> > cost(n+1,vector<ll>(0));
    vector<vector<ll> > adjRev(n+1,vector<ll>(0));
    vector<vector<ll> > costRev(n+1,vector<ll>(0));
    vector<pair<pair<ll,ll>, ll> > edges;
    for(ll i=0;i<m;i++){
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].pb(b);
        cost[a].pb(c);
        adjRev[b].pb(a);
        costRev[b].pb(c);
        edges.pb({{a,b},c});
    }
    set<pair<ll,ll> > s;
    s.insert(make_pair(0,1));
    for(ll i=2;i<=n;i++){
        s.insert(make_pair(1000000000000000,i));
    }
    vector<ll> dist(n+1,1000000000000000);
    dist[1] = 0;
    while(s.size()>0){
        ll v = s.begin()->second;
        s.erase(s.begin());
        for(ll i=0;i<adj[v].size();i++){
            ll prevCost = dist[adj[v][i]];
            if(dist[v]+cost[v][i]<prevCost){
                pair<ll,ll> p = make_pair(prevCost,adj[v][i]);
                s.erase(p);
                s.insert(make_pair(dist[v]+cost[v][i],adj[v][i]));
                dist[adj[v][i]] = dist[v]+cost[v][i];
            }
        }
    }
    s.insert(make_pair(0,n));
    for(ll i=1;i<n;i++){
        s.insert(make_pair(1000000000000000,i));
    }
    vector<ll> dist1(n+1,1000000000000000);
    dist1[n] = 0;
    while(s.size()>0){
        ll v = s.begin()->second;
        s.erase(s.begin());
        for(ll i=0;i<adjRev[v].size();i++){
            ll prevCost = dist1[adjRev[v][i]];
            if(dist1[v]+costRev[v][i]<prevCost){
                pair<ll,ll> p = make_pair(prevCost,adjRev[v][i]);
                s.erase(p);
                s.insert(make_pair(dist1[v]+costRev[v][i],adjRev[v][i]));
                dist1[adjRev[v][i]] = dist1[v]+costRev[v][i];
            }
        }
    }
    ll min1 = LLONG_MAX;
    for(ll i=0;i<m;i++){
        min1 = min(min1,edges[i].second/2+dist[edges[i].first.first]+dist1[edges[i].first.second]);
    }
    cout << min1 << endl;
} 
