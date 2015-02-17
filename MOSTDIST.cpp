#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define get(a) scanf("%lld", &a)
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for(vector< pair<ll,ll> >::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set < pair<ll,ll> >::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<double> >
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

int main() {
	ll q; get(q);
	vector< pair<ll,ll> > v;
	set< pair<ll,ll> > s1,s2,s3,s4;
	v.pb( mp(0,0) );
	ll ans = 0;
	
	while(q--) {
		char a[2];
		scanf("%s", &a);
		
		if( a[0] == '+' ) {
			ll x, y; get(x); get(y);
			x ^= ans; y ^= ans;
			
			v.pb( mp( x, y ) );
			s1.insert( mp( x, y ) );
			s2.insert( mp( y, -x ) );	
			s3.insert( mp( x, -y ) );
			s4.insert( mp( y, x ) );		
		}
		else if( a[0] == '-' ) {
			ll x; get(x); x ^= ans;
			s1.erase( mp( v[x].F, v[x].S ) );
			s2.erase( mp( v[x].S, -v[x].F ) );
			s3.erase( mp( v[x].F, -v[x].S ) );
			s4.erase( mp( v[x].S , v[x].F ) );
			//v[x] = mp( -1, -1 );
			
		}	
		else if( a[0] == '?' ) {
			ll x, y;
			get(x); get(y);
			x ^= ans; y ^= ans;
			
			
			
			/*ll tans = 0;
			
			repSet(s1)
				tans = max( tans, abs( x - it->F ) + abs( y - it->S ) );
			*/
			//cout << " ORG: " << x << " " << y << endl;
			ll tans = abs( x - s1.rbegin()->F ) + abs( y - s1.rbegin()->S );
			tans = max( tans, abs( x - s1.begin()->F ) + abs( y - s1.begin()->S ) );
			tans = abs( x - s4.rbegin()->S ) + abs( y - s4.rbegin()->F );
			tans = max( tans, abs( x - s4.begin()->S ) + abs( y - s4.begin()->F ) );
			
			tans = max( tans, abs( x + s2.begin()->S ) + abs( y - s2.begin()->F ) );
			tans = max( tans, abs( x + s2.rbegin()->S ) + abs( y - s2.rbegin()->F ) );
			tans = max( tans, abs( x - s3.begin()->F ) + abs( y + s3.begin()->S ) );
			tans = max( tans, abs( x - s3.rbegin()->F ) + abs( y + s3.rbegin()->S ) );
			
			ans = tans;
			printf("%lld\n", ans);	
		}
	
	}
}
