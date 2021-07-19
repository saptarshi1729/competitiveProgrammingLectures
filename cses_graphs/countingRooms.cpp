#include <bits/stdc++.h> 
using namespace std;

#define pb push_back
#define ll long long int
#define loop(i,a,b,c) for(i=a;i<b;i+=c)
#define endl "\n"

void visit(ll n, ll m, vector<vector<ll> >& vis, vector<string>& v, ll curri, ll currj){
    if(curri<0||curri>=n||currj<0||currj>=m)
        return;
    if(v[curri][currj]=='#'||vis[curri][currj]==1)
        return;
    vis[curri][currj] = 1;
    visit(n,m,vis,v,curri+1,currj);
    visit(n,m,vis,v,curri-1,currj);
    visit(n,m,vis,v,curri,currj+1);
    visit(n,m,vis,v,curri,currj-1);
}

int main() 
{ 
    ll n, m;
    cin >> n;
    cin >> m;
    vector<string> v(n);
    for(ll i=0;i<n;i++){
        string s;
        cin >> s;
        v[i] = s;
    }
    vector<vector<ll> > vis;
    for(ll i=0;i<n;i++){
        vector<ll> a(m,0);
        vis.pb(a);
    }
    ll rooms = 0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(v[i][j]=='#'||vis[i][j]==1)
                continue;
            visit(n,m,vis,v,i,j);
            rooms++;
        }
    }
    cout << rooms << endl;
} 

