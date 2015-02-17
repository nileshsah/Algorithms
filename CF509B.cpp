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
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

int main() {
	ll n, k;
	cin >> n >> k;
	vector<ll> v, ans[105];
	
	FOR(i,1,n)
	 { ll x; cin >> x; v.pb(x); }
	
	FOR(i,1,k) {
		ll minx = *min_element( all(v) );
		ll maxx = *max_element( all(v) );
		
		if( maxx == minx ) {
		 FOR(j,0,n-1)
		  if( v[j] > 0 ) {
		  	FOR(k,1,minx)
		  	 ans[j].pb(i);
		  	v[j] = 0;
		  }
		   break;
		}
		
		ll num = minx;
		
		FOR(j,0,n-1)
		  if( v[j] == maxx ) {
		  	FOR(k,1,num+1)
		  	 ans[j].pb(i);
		  	v[j] -= num+1;
		  }
		  else {
		  	FOR(k,1,num)
		  	 ans[j].pb(i);
		  	v[j] -= num;
		  }
		
	}
	
	FOR(i,0,n-1)
	 if( v[i] > 0 )
	 	{ cout << "NO"; return 0; }
	
	cout << "YES\n";
	
	FOR(i,0,n-1) {
	  repVector(ans[i])
	  	cout << *it << " ";
	  cout << "\n";
	}
	
}

