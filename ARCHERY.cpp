#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( multiset<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

vector<ll> r;

int bsrch( ll start, ll end, ll val ) {
	ll mid = ( start + end )/2;
	
	if( start > end )
		return start;
	
	if( r[mid] == val )
		return mid;
	else if( r[mid] > val ) 
		return bsrch( start, mid-1, val );
	else 
		return bsrch( mid+1, end, val ); 
}

int main() {
	ll n; get(n);
	
	rep(n) { ll x; get(x); r.pb(x); }
	sort( all(r) );
	
	ll m; get(m);
	vector< pair< pair<ll,ll>, pair<ll,ll> > > v;
	
	ll ans = 0;
	
	rep(m) { 
	  ll x1, x2, y1, y2; 
	  get(x1); get(y1); get(x2); get(y2);
	  
	  ll minR = min( x1*x1 + y1*y1, x2*x2 + y2*y2 );
	  ll maxR = max( x1*x1 + y1*y1, x2*x2 + y2*y2 );
	  minR = sqrt(minR); maxR = sqrt(maxR);
		
	  ans += bsrch( 0, r.size()-1, maxR ) - bsrch( 0, r.size()-1, minR );

	  v.pb( mp( mp(x1,y1), mp(x2,y2) ) );
	}
	
	//sort( all(v) );
	
	cout << ans;
	
}
