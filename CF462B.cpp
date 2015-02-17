#include <bits/stdc++.h>
#define ll long long
#define get(a) cin >> a;
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

int main() {
//	INPFILE;
	ll n, k;
	cin >> n >> k;
	
	string s;
	cin >> s;
	
	vector<ll> v(28,0);
	
	FOR(i,0,n-1)
	 v[ s[i] - 'A' ]++;
	
	sort( all(v), greater<ll>() );
	ll ans = 0, i = 0;
	
	while( k != 0 )
	 if( v[i] <= k )
	  { ans += v[i]*v[i]; k -= v[i]; i++; }
	 else 
	  { ans += k*k; k = 0; }
	
	cout << ans;
	 
	 

}
