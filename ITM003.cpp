#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cout << "[DEBUG]" << #x << " " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

map<ll,ll> dp;

ll rec( ll n ) {
	if( dp.find(n) != dp.end() )
		return dp[n];
	if( n%2 )
		return dp[n] = 1 + rec(n-1);
	else
		return dp[n] = rec(n/2);
}

int main() {

	dp[1] = 1; dp[2] = 1;
	
	ll t; get(t);
	while(t--) {
		ll n; get(n);
		cout << rec(n) << endl;
		
	}
}
