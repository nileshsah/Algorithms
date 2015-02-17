#include <bits/stdc++.h>
#define ll int
#define get(a) scanf("%d", &a)
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

int main() {
//	INPFILE;
	ll t; get(t);
	while(t--) {
		map< pair<ll,ll>, bool > dp;
		ll a1, b1, c, a, b;
		get(a1); get(b1); get(c);
		
		a = max(a1,b1); b = min(a1,b1);
		set< pair<ll,pair<ll,ll> > > s;
		s.insert( mp(0,mp(0,0) ) );
		
//		memset( dp, 0, sizeof dp );
		ll ans = -1;
		
		while(!s.empty()) {
			ll x = s.begin()->S.F;
			ll y = s.begin()->S.S;
			ll step = s.begin()->F;
			s.erase(s.begin());
			
			if( dp[mp(x,y)]  )
				continue;
			else
				dp[mp(x,y)] = 1;
			
			if( x == c || y == c )
			  { ans = step; break; }
			
			if( y == 0 )
			 s.insert( mp(step+1,mp(x,b) ) );
			else if( y == b )
			 s.insert( mp(step+1,mp(x,0) ) );
			if( x == 0 )
			 s.insert( mp(step+1,mp(a,y) ) );
			else if( x == a )
			 s.insert( mp(step+1,mp(0,y) ) );
			
			ll nx = x - min(x,(b-y)), ny = y+min(x,(b-y));
			 s.insert( mp(step+1,mp(nx,ny)) );
			nx = x + min(y,(a-x)); ny = y-min(y,(a-x));
			 s.insert( mp(step+1,mp(nx,ny)) );
			

		}
		
		printf("%d\n", ans);
		
		
	}
}
