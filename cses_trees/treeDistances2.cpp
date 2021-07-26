#include <bits/stdc++.h> 
using namespace std;

#define pb push_back
#define ll long long int
#define loop(i,a,b,c) for(i=a;i<b;i+=c)

void findInsideSubtree(ll curr, vector<vector<ll> >& nhb, vector<ll>& in, vector<ll>& sz, int par){
    sz[curr] = 1;
    for(int y:nhb[curr]){
        if(par==y)
            continue;
        findInsideSubtree(y,nhb,in,sz,curr);
        sz[curr] += sz[y];
        in[curr] += in[y];
    }
    in[curr] += (sz[curr]-1);
}

void findOutsideSubtree(ll curr, vector<vector<ll> >& nhb, vector<ll>& out, vector<ll>& sz, vector<ll>& in, int par, int n){
    if(curr!=par){
        out[curr] = out[par];
        out[curr] += (n-sz[par]);
        out[curr] += (in[par]-in[curr]-sz[curr]) + (sz[par]-sz[curr]);
    }
    for(ll y:nhb[curr]){
        if(y==par)
            continue;
        findOutsideSubtree(y,nhb,out,sz,in,curr,n);
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
    vector<ll> in(n+1,0);
    vector<ll> out(n+1,0);
    vector<ll> sz(n+1,0);
    findInsideSubtree(1,nhb,in,sz,1);
    findOutsideSubtree(1,nhb,out,sz,in,1,n);
    for(ll y=1;y<=n;y++){
        cout << (in[y]+out[y]) << " ";
    }
    cout << endl;
}