#include <bits/stdc++.h>
#define ll long
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

int main() {
	ll n; get(n);		
	map< pair<ll,ll> , bool> mask;
	
	vector<ll> v;
	ll ans = 0;
	
	FOR(i,0,n-1) { 
	  ll x; get(x); 
	  v.pb(x);
	  if( i != x )   
	   mask[mp(i,x)] = 1;
	  else
	   ans++;
	}
	
	bool flag = 0;
	
	repSet(mask)
	 if( mask.find(mp(it->F.S,it->F.F)) != mask.end() )
	   { flag = 1; break; }
	
	if( !flag && ans == n )
	   ans -= 2;
	else if( !flag )
	   ans += 1;
	else if( flag )
		ans += 2;
	
	printf("%ld", ans);
 
}
