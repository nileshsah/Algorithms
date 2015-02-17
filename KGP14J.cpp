#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for( vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define max(a,b) ( (a > b) ? a : b )
#define min(a,b) ( (a < b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

ll num( ll n ) {
	ll ans = 0;
	while( n != 0 )
	 { n /= 10; ans++; }
	
	return ans;
}

ll solve( ll n, ll k ) {
	ll s = num(n);
	
	if( s <= k )
		return n;
	
	while( s > k )
	 { n /= 10; s--; }
	 
	return n;
		
}

int main() {
	ll t, c = 1; get(t);
	while(t--) {
		ll x = 0, y = 0;
		string a, b;
		cin >> a >> b;
	    
	    rep(a.size())
	    	{ x *= 10; x += a[i] - '0'; }
	    rep(b.size())
	      { y *= 10; y += b[i] - '0'; }
	    
	    if( x == y )
	      { printf("Case %lld: %lld\n",c++, 1); continue; }
	    if( a.size() > b.size() && a.substr(0,b.size()) == b )
	      { printf("Case %lld: %lld\n",c++, 1); continue; }
	   
		ll ans = 1;
		long long unsigned val = x;
		
		while(1) {
			val *= x;
	//		cout << " SOL: " << ans+1 << " " << solve(val,b.size()) << endl;
			if( solve(val,b.size()) == y )
			 { printf("Case %lld: %lld\n",c++, ans+1); break; }
			val = solve( val, 17 - a.size() );
			ans++;
		}
		
	}
}
