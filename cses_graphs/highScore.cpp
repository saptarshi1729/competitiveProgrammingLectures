#include <bits/stdc++.h> 
using namespace std;

#define pb push_back
#define ll long long int
#define loop(i,a,b,c) for(i=a;i<b;i+=c)
#define endl "\n"

bool checkReachable(ll curr, vector<ll>& vis, vector<vector<ll> >& nhb, ll n){
    if(vis[curr])
        return false;
    if(curr==n){
        return true;
    }
    vis[curr] = true;
    bool res = false;
    for(ll y:nhb[curr]){
        res |= checkReachable(y,vis,nhb,n);
    }
    return res;
}

int main() 
{ 
    ll n, m, q;
    cin >> n;
    cin >> m;
    vector<ll> dist(n+1,-1000000000000000);
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
            if(dist[src[j]]+cost[j]>dist[dest[j]]&&dist[src[j]]!=-1000000000000000){
                flag = 1;
                dist[dest[j]] = dist[src[j]]+cost[j];
            }
        }
        if(flag==0)
            break;
    }
    for(ll j=0;j<m;j++){
        if(dist[src[j]]+cost[j]>dist[dest[j]]&&dist[src[j]]!=-1000000000000000){
            dist[dest[j]] = dist[src[j]]+cost[j];
            vector<ll> vis(n+1);
            bool res = checkReachable(dest[j],vis,nhb,n);
            if(res==true){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << (dist[n]==-1000000000000000?-1:dist[n]) << endl;
} 
