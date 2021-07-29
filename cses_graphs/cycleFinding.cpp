#include <bits/stdc++.h> 
using namespace std;

#define pb push_back
#define ll long long int
#define loop(i,a,b,c) for(i=a;i<b;i+=c)
#define endl "\n"

int main() 
{ 
    ll n, m, q;
    cin >> n;
    cin >> m;
    vector<ll> dist(n+1,1000000000000000);
    vector<ll> prev(n+1,-1);
    dist[1] = 0;
    vector<ll> src(m,0);
    vector<ll> dest(m,0);
    vector<ll> cost(m,0);
    vector<vector<ll> > nhb(n+1,vector<ll>());
    for(ll i=0;i<m;i++){
        ll a, b, c;
        cin >> src[i] >> dest[i] >> cost[i];
        nhb[src[i]].pb(dest[i]);
    }
    for(ll i=0;i<n-1;i++){
        int flag = 0;
        for(ll j=0;j<m;j++){
            if(dist[src[j]]+cost[j]<dist[dest[j]]){
                flag = 1;
                dist[dest[j]] = dist[src[j]]+cost[j];
                prev[dest[j]] = src[j];
            }
        }
        if(flag==0)
            break;
    }
    ll target = -1;
    for(ll j=0;j<m;j++){
        if(dist[src[j]]+cost[j]<dist[dest[j]]){
            dist[dest[j]] = dist[src[j]]+cost[j];
            prev[dest[j]] = src[j];
            target = dest[j];
            break;
        }
    }
    if(target == -1){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    vector<ll> path;
    path.pb(target);
    ll curr = target;
    set<ll> seen;
    seen.insert(target);
    while(true){
        path.pb(prev[curr]);
        if(seen.find(prev[curr])!=seen.end()){
            target = prev[curr];
            break;
        }
        seen.insert(prev[curr]);
        curr = prev[curr];
    }
    for(ll i=path.size()-1;i>=0;i--){
        cout << path[i] << " ";
        if(i<path.size()-1&&path[i]==target)
            break;
    }
    cout << endl;
} 
