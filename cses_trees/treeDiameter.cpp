#include <bits/stdc++.h> 
using namespace std;

#define pb push_back
#define ll long long int
#define loop(i,a,b,c) for(i=a;i<b;i+=c)

void findFarthest(ll curr, vector<ll>& dist, vector<vector<ll> >& nhb, ll d){
    if(dist[curr]>=0)
        return;
    dist[curr] = d;
    for(ll a:nhb[curr]){
        findFarthest(a,dist,nhb,d+1);
    }
}

int main(){
    ll n;
    cin >> n;
    vector<vector<ll> > nhb(n+1,vector<ll>(0));
    for(ll i=2;i<=n;i++){
        ll a, b;
        cin >> a >> b;
        nhb[a].pb(b);
        nhb[b].pb(a);
    }
    if(n==1){
        cout << 0 << endl;
        return 0;
    }
    ll leaf = 0;
    for(ll i=1;i<=n;i++){
        if(nhb[i].size()==1){
            leaf = i;
            break;
        }
    }
    vector<ll> dist(n+1,-1);
    findFarthest(leaf,dist,nhb,0);
    ll maxi = -1, max = -1;
    for(ll i=1;i<=n;i++){
        if(dist[i]>max){
            max = dist[i];
            maxi = i;
        }
    }
    vector<ll> dist1(n+1,-1);
    findFarthest(maxi,dist1,nhb,0);
    max = -1;
    maxi = -1;
    for(ll i=1;i<=n;i++){
        if(dist1[i]>max){
            max = dist1[i];
            maxi = i;
        }
    }
    cout << max << endl;
}