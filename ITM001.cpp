#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cout << "[DEBUG]" << #x << " " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

int main() {
	ll q; get(q);
	while(q--) {
		ll a, b;
		get(a); get(b);
		
		ll ans = 0;
		
		double val = -1 + sqrt( 1 + 8.0*a );
		val /= 2;
		ll value = ceil(val);
		
		ll start = value*(value-1)/2;
		start++;
		
		ll x = a - start;
		start = value;
		ll cx = value+1;
		
		if( value%2 && x%2 == 0 )
		 ans += value;
		else if( value%2 == 0 && x%2 )
		  ans -= value;
		  
//	debug(ans);

		
		val = -1 + sqrt( 1 + 8.0*b );
		val /= 2;
		value = ceil(val);
		
		ll end = value*(value-1)/2;
		end++;
		
		ll y = b - end;
		end = value;
		ll cy = value-1;
		
		if( value%2 != 0 && y%2 == 0 )
		  ans += value;
		else if( value%2 == 0 && y%2 == 0 )
		  ans += value;
		  
//		debug(ans);

		
		if( end == start && a != b )
		 if( (x+y)%2 ) {
		 	cout << "0\n"; continue;
		 }
		 else if( x%2 == 0 && y%2 == 0 )
		  { cout << end << endl; continue; }
		 else
		  { cout << -abs(end) << endl; continue; }

	
	 if( cy >= cx ) {
		cy /= 2; cx /=2 ;	
		ans += cy*cy - cx*cx;
	 }
//		debug(ans);
		
		if( a == b && x%2 )
		  ans = -abs(ans);
		

		cout << ans << endl;
		
	}
}
