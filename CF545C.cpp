#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
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

vector< pair<ll,ll> > v;
ll dp[100005][3] = {0};

ll rec( ll ptr, ll last ) {
	if( ptr == v.size()-1 )
		return 0;
	if( dp[ptr][last+1] != -1 )
		return dp[ptr][last+1];
	ll val = 0;
	
	if(  v[ptr].F - v[ptr].S > max(v[ptr-1].S*last + v[ptr-1].F,v[ptr-1].F) )
	  val = max( val, 1+rec(ptr+1,-1) );
	if( v[ptr].F + v[ptr].S < v[ptr+1].F )
	 val = max( val, 1+rec(ptr+1,1) );
	val = max( val, rec(ptr+1,0) );
	
//	cout << "REC: " << v[ptr].F << " " << last << " = " << val << '\n';
	return dp[ptr][last+1] = val;
}


int main() {
//	INPFILE;
	memset(dp,-1,sizeof dp);

	v.pb( mp(LONG_MIN,LONG_MIN) );
	
	ll n; cin >> n;
	FOR(i,1,n) {
		ll x, h;
		cin >> x >> h;
		v.pb( mp(x,h) );
	}
	v.pb( mp(LONG_MAX,LONG_MAX) );
	
	cout << rec(1,0);
	
}
