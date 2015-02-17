#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a);
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

vector<ll> v;

ll LIS() {
	vector<ll> dp(v.size()+1,1);
	
	FOR(i,0,v.size()-1)
	 for( ll j = i-1; j >= 0; j-- )
	 	if( v[i] > v[j] )
	 	 dp[i] = max( dp[i], dp[j]+1 );
	
	return *max_element( all(dp) );
}

int main() {
	ll n; get(n);
	rep(n)
	 { ll x; get(x); v.pb(x); }
	
	printf("%ld\n", LIS());
}
