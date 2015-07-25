#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
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
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main() {
	ll n, k;
	cin >> n >> k;
	
	ll ans = 0, maxlen = 0;
	
	FOR(i,1,k) {
	  ll x; cin >> x;
	  vector<ll> v;
	  FOR(j,1,x)
		{ ll p; cin >> p; v.pb(p); }
	  ll ptr = 1, len = 0;
	  if( v[0] == 1 )
	   while( ptr < x && v[ptr-1] == v[ptr] - 1 )
	    len++, ptr++;
	  maxlen = max( maxlen, len );  
	  ans += x-1; 
	}
	
//	debug(maxlen);
	
	ans += n-1;
	ans -= 2*maxlen;
	
	cout << ans;
	
	
}
