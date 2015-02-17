#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
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

int main() {
	ll n; get(n);
	vector<ll> v;
	
	rep(n)
	 { ll x; get(x); v.pb(x); }
	
	ll ans[n+1];
	ans[0] = v[0];
	ans[n+1] = 0;
	
	ll val = INT_MIN;

	FOR(i,0,n-2)
	 ans[i] = max( ans[i-1], v[i+1] - v[i] );
	
	ll val = 0;
	
	FOR(i,0,n-2)
	 val = min( val, v[i+2] - v[i] );
	
	cout << max(ans,ans;
	 
}

