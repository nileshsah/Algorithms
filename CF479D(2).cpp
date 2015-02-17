#include <bits/stdc++.h>
#define ll long long
#define get(a) cin >> a
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
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

map<ll,bool> mark;

int main() {
	INPFILE;
	ll n, l, x, y;
	cin >> n >> l >> x >> y;
	vector<ll> v(n), vec, vec2;
	
	rep(n) { 
	  get(v[i]); 
	  mark[v[i]] = 1;
	  if( v[i] - x > 0 )
	   vec.pb( (v[i]-x) );
	  if( v[i] - y > 0 )
	  vec2.pb( (v[i]-y) );
	  vec.pb(v[i]); 
	}
	
	vector< pair<ll,pair<ll,ll> > > ans;
	ans.pb( mp( 2, mp(x,y) ) );
	
	bool exp1 = binary_search( all(v), x );
	bool exp2 = binary_search( all(v), y );
	
	if( exp1 && exp2 )
	  { cout << "0"; return 0; }
	
	bool xx, yy;
	
	repVector(vec) {
	 ll i = *it;

	  xx = binary_search( all(v), i+y );
	  yy = binary_search( all(v), i-y );
	 
	 if( xx || yy && !mark[i] )
	 	 ans.pb( mp( 1, mp(i,-1) ) );
	 else if( xx || yy && mark[i] )
	   { ans.pb( mp( 0, mp(-1,-1) ) ); break; }
	}
	
	repVector(vec2) {
	 ll i = *it;

     xx = binary_search( all(v), i+x );
	 yy = binary_search( all(v), i-x );
	 
	 if( xx || yy && !mark[i] )
	 	 ans.pb( mp( 1, mp(i,-1) ) );
	 else if( xx || yy && mark[i] )
	   { ans.pb( mp( 0, mp(-1,-1) ) ); break; }
	}
	
	sort( all(ans) );
	
	cout << ans[0].F << endl;
	if( ans[0].S.F != -1 )
	  cout << ans[0].S.F << endl;
	if( ans[0].S.S != -1 )
	  cout << ans[0].S.S << endl;
	
	  
}
