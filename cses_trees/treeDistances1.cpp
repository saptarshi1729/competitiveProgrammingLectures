#include <bits/stdc++.h> 
using namespace std;

#define pb push_back
#define ll long long int
#define loop(i,a,b,c) for(i=a;i<b;i+=c)

void findDistances(ll curr, vector<ll>& dist, vector<vector<ll> >& nhb, ll d){
    if(dist[curr]>=0)
        return;
    dist[curr] = d;
    for(ll a:nhb[curr]){
        findDistances(a,dist,nhb,d+1);
    }
}

int main(){
    ll n;
    cin >> n;
    vector<vector<ll> > nhb(n+1,vector<ll>(0));
    vector<ll> deg(n+1,0);
    for(ll i=2;i<=n;i++){
        ll a, b;
        cin >> a >> b;
        nhb[a].pb(b);
        nhb[b].pb(a);
        deg[a]++;
        deg[b]++;
    }
    if(n==1){
        cout << 0 << endl;
        return 0;
    }
    set<pair<ll,ll>> nodes;
    for(ll i=1;i<=n;i++){
        nodes.insert({deg[i],i});
    }
    vector<ll> removed(n+1,0);
    ll d = 0;
    while(nodes.size()>2){
        vector<ll> nodesToBeUpdated;
        while(nodes.begin()->first==1){
            ll v = nodes.begin()->second;
            for(ll a:nhb[v]){
                if(removed[a]==0){
                    nodesToBeUpdated.pb(a);
                }
            }
            removed[v] = 1;
            nodes.erase(nodes.begin());
        }
        for(ll x:nodesToBeUpdated){
            auto y = nodes.find({deg[x],x});
            nodes.erase(y);
            deg[x]--;
            nodes.insert({deg[x],x});
        }
        d++;
    }
    vector<ll> dist(n+1,-1);
    if(nodes.size()==1){
        findDistances(nodes.begin()->second,dist,nhb,d);
        for(ll i=1;i<=n;i++){
            cout << dist[i] << " ";
        }
        cout << endl;
    }
    else{
        int v1 = nodes.begin()->second;
        nodes.erase(nodes.begin());
        int v2 = nodes.begin()->second;
        dist[v2] = d;
        findDistances(v1,dist,nhb,d);
        dist[v2] = -1;
        dist[v1] = d;
        findDistances(v2,dist,nhb,d);
        for(ll i=1;i<=n;i++){
            cout << (1+dist[i]) << " ";
        }
        cout << endl;
    }
}