#include <bits/stdc++.h>
#include <cstdio>
#define ll int
#define get(a) scanf("%d", &a)
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for(vector< pair<ll,ll> >::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set< pair< ll, pair<ll,ll> > >::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<double> >
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

ll dp[2500][2500] = {0};

ll dfs( ll h, ll a, ll pos, ll count = 1 ) {
	ll m = 0;

	if( pos == 0 )
	  { h += 3; a += 2; }
	else if( pos == 1 )
	 {  h -= 20; a += 5; }
	else if( pos == 2 )
	 { h -= 5; a -= 10; }
	
	if( h <= 0 || a <= 0 )
		return count-1;

	 //cout << " REC: " << h << " " << a << endl;
	
		
	FOR(i,0,2) {
	 if( pos == i )
	 	continue;
	 else m = max( m, ( ( dp[h][a] != 0 ) ? dp[h][a] : dfs( h, a, i, count+1 ) ) );
	}
	
	 dp[h][a] =  m;
	return m;
}

int main() {
	int t; get(t);
	while(t--) {
		ll h, a;
		get(h); get(a);
		memset( dp, 0, sizeof dp );
		
		printf("%ld\n", dfs(h,a,0));
	}
}
