#include <bits/stdc++.h> 
using namespace std;

#define pb push_back
#define ll long long int
#define loop(i,a,b,c) for(i=a;i<b;i+=c)

void findMaxMatching(ll curr, vector<vector<ll> >& children, vector<ll>& maxEdges1, vector<ll>& maxEdges2, vector<bool>& visited){
    ll sum1 = 0;
    visited[curr] = 1;
    vector<ll> children1;
    for(ll i=0;i<children[curr].size();i++){
        if(visited[children[curr][i]])
            continue;
        findMaxMatching(children[curr][i],children,maxEdges1,maxEdges2,visited);
        sum1 += maxEdges1[children[curr][i]];
        children1.pb(i);
    }
    maxEdges2[curr] = sum1;
    maxEdges1[curr] = sum1;
    for(ll i=0;i<children1.size();i++){
        ll v = children[curr][children1[i]];
        // cout << curr << " " << v << " " << maxEdges1[v] << endl;
        maxEdges1[curr] = max(maxEdges1[curr],1+maxEdges2[v]+sum1-maxEdges1[v]);
    }
}

int main(){
    ll n;
    cin >> n;
    vector<vector<ll> > children(n+1,vector<ll>(0));
    for(ll i=2;i<=n;i++){
        ll a, b;
        cin >> a >> b;
        children[a].pb(b);
        children[b].pb(a);
    }
    vector<bool> visited(n+1,0);
    vector<ll> maxEdges1(n+1,0);
    vector<ll> maxEdges2(n+1,0);
    ll ans = 0;
    for(ll i=1;i<=n;i++){
        if(visited[i])
            continue;
        findMaxMatching(i,children,maxEdges1,maxEdges2,visited);
        ans += maxEdges1[i];
    }
    cout << ans << endl;
}