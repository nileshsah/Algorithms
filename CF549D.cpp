#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( auto it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
#define MOD 1000000000
#define foo pair< pair<ll,ll>, ll >
using namespace std;

int modify[105][105] = {0};
ll arr[105][105] = {0};


int main() {
//	INPFILE;
   ll n, m;
   cin >> n >> m;
   char str[n+2][m+2];
   
   memset( modify, -1, sizeof modify );
   
   FOR(i,1,n)
    FOR(j,1,m) {
     cin >> str[i][j];
     if( str[i][j] == 'W' )
      arr[i][j] = 1;
  	}
  
  ll ans = 0;
  
  str[n][m+1] = 'x';  
  char last = 'x';
  
  ROF(i,m,1) 
   ROF(j,n,1) 
    if( arr[j][i] != modify[j][i] ) {
       ll diff = modify[j][i] - arr[j][i];
     FOR(p,1,i)
      FOR(q,1,j)
       modify[q][p] -= diff;
     ans++;
    }
      
  cout << ans;
    
}
