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
    cin >> q;
    vector<vector<ll> > dp(n+1,vector<ll>(n+1,1000000000000000));
    for(ll i=1;i<=n;i++){
        dp[i][i] = 0;
    }
    for(ll i=0;i<m;i++){
        ll a, b, c;
        cin >> a >> b >> c;
        dp[a][b] = min(c,dp[a][b]);
        dp[b][a] = dp[a][b];
    }
    for(ll k=1;k<=n;k++){
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                if(dp[i][k]!=1000000000000000&&dp[k][j]!=1000000000000000)
                    dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    for(ll i=0;i<q;i++){
        ll a, b;
        cin >> a >> b;
        cout << (dp[a][b]==1000000000000000?-1:dp[a][b]) << endl;
    }
} 
