#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

ll dp[2005][2005] = {0};
ll idx[2005][2005] = {0};


int main() {
	
	FOR(i,1,2000)
	 dp[i][0] = 1;
	
	FOR(i,1,2000) {
	 FOR(j,1,i-1)
	  { dp[i][j] = ( dp[i][j-1] + ( ( i-1 > j ) ? dp[i-1][j] : 0 ) )%MOD;  }//cout << dp[i][j] << " "; }
//	 cout << endl;
	}
		
	FOR(i,1,2000)
	 idx[0][i] = 1;
	
	FOR(j,1,2000) {
	  FOR(i,1,j)
	    idx[i][j] = ( idx[i-1][j] + ( ( j-1 >= i ) ? idx[i][j-1] : 0 ) )%MOD;
	}
	
	
	 
	INPFILE;
	ll t, w = 1; get(t);
	while(t--) {
		string s;
		cin >> s;
		ll a = 0, b = 0;
		ll i = 0;
		
		while( s[i] != '-' ) {
			a *= 10;
			a += s[i] - '0';
			i++;
		}
		
		FOR(k,i+1,s.size()-1)
		  { b *= 10; b+= s[k] - '0'; }
		
		printf("Case #%lld: %lld %lld\n", w++, dp[a][b], idx[b][b] );

	}
}
