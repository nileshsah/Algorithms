#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
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


int main() {
	ll m, t, r;
	cin >> m >> t >> r;
	vector<ll> v;

	ll count[10000] = {0};
	
	FOR(i,1,m)
	 { ll x; cin >> x; v.pb(r+x);  count[r+x] = r; }
	
	if( t < r )
	 { cout << "-1"; return 0; }
	 
	ll ans = 0;
	
	FOR(i,0,v.size()-1) {
	  ans += count[v[i]];
	  FOR(j,1,count[v[i]])
	   FOR(k,i+1,v.size()-1)
	    if( v[k] > v[i]+t-j ) break;
	    else if( v[k] <= v[i]+t-j )
			count[v[k]]--;  
			
/*	  FOR(k,0,v.size()-1)
	   cout << count[v[k]] << " ";
	  cout << endl;
*/
	}
	
	cout << ans;
	
	
}
