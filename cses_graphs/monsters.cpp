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
    vector<string> v(n);
    for(ll i=0;i<n;i++){
        string s;
        cin >> s;
        v[i] = s;
    }
    vector<vector<ll> > vis(n,vector<ll>(m,0));
    vector<vector<ll> > dist1(n,vector<ll>(m,100000000));
    ll starti = 0, startj = 0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(v[i][j]=='A'){
                starti = i;
                startj = j;
                break;
            }
        }
    }
    vector<ll> elementsX;
    vector<ll> elementsY;
    elementsX.pb(starti);
    elementsY.pb(startj);
    dist1[starti][startj] = 0;
    vector<ll> prev;
    prev.pb(-1);
    ll possX[] = {-1,1,0,0};
    ll possY[] = {0,0,-1,1};
    char moves[] = {'U','D','L','R'};
    vector<char> prevMove;
    prevMove.pb('X');
    vis[starti][startj] = 1;
    vector<vector<ll> > index(n,vector<ll>(m,0));
    index[starti][startj] = 0;
    for(ll i=0;i<elementsX.size();i++){
        ll curri = elementsX[i];
        ll currj = elementsY[i];
        for(ll j=0;j<4;j++){
            ll newi = curri+possX[j];
            ll newj = currj+possY[j];
            if(newi>=0&&newi<n&&newj>=0&&newj<m&&vis[newi][newj]==0){
                if(v[newi][newj]=='#')
                    continue;
                index[newi][newj] = elementsX.size();
                elementsX.pb(newi);
                elementsY.pb(newj);
                vis[newi][newj] = 1;
                prev.pb(i);
                prevMove.pb(moves[j]);
                dist1[newi][newj] = dist1[curri][currj] + 1;
            }
        }
    }  
    
    vector<vector<ll> > vis2(n,vector<ll>(m,0));
    vector<vector<ll> > dist2(n,vector<ll>(m,100000000));
    vector<ll> elementsX2;
    vector<ll> elementsY2;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(v[i][j]=='M'){
                elementsX2.pb(i);
                elementsY2.pb(j);
                dist2[i][j] = 0;
                vis2[i][j] = 1;
            }
        }
    }
    for(ll i=0;i<elementsX2.size();i++){
        ll curri = elementsX2[i];
        ll currj = elementsY2[i];
        for(ll j=0;j<4;j++){
            ll newi = curri+possX[j];
            ll newj = currj+possY[j];
            if(newi>=0&&newi<n&&newj>=0&&newj<m&&vis2[newi][newj]==0){
                if(v[newi][newj]=='#')
                    continue;
                elementsX2.pb(newi);
                elementsY2.pb(newj);
                vis2[newi][newj] = 1;
                dist2[newi][newj] = dist2[curri][currj] + 1;
            }
        }
    }  
    ll endi = -1, endj = -1;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if((i==0||j==0||i==n-1||j==m-1)&&dist2[i][j]>dist1[i][j]){
                endi = i;
                endj = j;
            }
        }
    }
    if(endi!=-1){
        cout << "YES" << endl;
        ll curr = index[endi][endj];
        ll curri = endi, currj = endj;
        vector<char> path;
        ll d = dist1[curri][currj];
        while(d-->0){
            path.pb(prevMove[curr]);
            curr = prev[curr];
        }
        cout << path.size() << endl;
        for(ll i=path.size()-1;i>=0;i--){
            cout << path[i];
        }
        cout << endl;
    }
    else{
        cout << "NO" << endl;
    }
} 
