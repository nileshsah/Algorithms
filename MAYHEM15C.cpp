#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( auto it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
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
using namespace std;

double dp[1005][1005] = {0};
bool explore[1005][1005] = {0};
double mat[1005][1005] = {0};
ll n, m;

double rec( ll a, ll b, ll c = 1 ) {
	if( a > n || b > m )
		return c-1;
	if( explore[a][b] )
	  return dp[a][b];
	
    dp[a][b] = mat[a][b]*rec( a, b+1, c+1 ) + (1-mat[a][b])*rec( a+1, b, c+1 );
	explore[a][b] = 1;
	return dp[a][b];
}

int main() {
	ll t; scanf("%d",&t);
	while(t--) {
	    memset( explore, 0, sizeof explore );
	   scanf("%d%d", &n,&m);
	   FOR(i,1,n)
	    FOR(j,1,m)
	     scanf("%lf",&mat[i][j]);
	  printf("%0.6lf\n",rec( 1, 1 ));
	}
}
