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
    vector<vector<ll> > vis;
    for(ll i=0;i<n;i++){
        vector<ll> a(m,0);
        vis.pb(a);
    }
    ll starti = 0, endi = 0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(v[i][j]=='A'){
                starti = i;
                endi = j;
                break;
            }
        }
    }
    vector<ll> elementsX;
    vector<ll> elementsY;
    elementsX.pb(starti);
    elementsY.pb(endi);
    vector<ll> prev;
    prev.pb(-1);
    ll possX[] = {-1,1,0,0};
    ll possY[] = {0,0,-1,1};
    char moves[] = {'U','D','L','R'};
    vector<char> prevMove;
    prevMove.pb('X');
    ll end = -1;
    for(ll i=0;i<elementsX.size();i++){
        ll curri = elementsX[i];
        ll currj = elementsY[i];
        if(v[curri][currj]=='B'){
            end = i;
            break;
        }
        for(ll j=0;j<4;j++){
            if(curri+possX[j]>=0&&curri+possX[j]<n&&currj+possY[j]>=0&&currj+possY[j]<m&&vis[curri+possX[j]][currj+possY[j]]==0){
                if(v[curri+possX[j]][currj+possY[j]]=='#')
                    continue;
                elementsX.pb(curri+possX[j]);
                elementsY.pb(currj+possY[j]);
                vis[curri+possX[j]][currj+possY[j]] = true;
                prev.pb(i);
                prevMove.pb(moves[j]);
            }
        }
    }  
    if(end==-1){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        ll curr = end;
        vector<char> path;
        while(curr!=-1){
            path.pb(prevMove[curr]);
            curr = prev[curr];
        }
        cout << path.size()-1 << endl; 
        for(ll i=path.size()-2;i>=0;i--){
            cout << path[i];
        }
        cout << endl;
    }
} 
