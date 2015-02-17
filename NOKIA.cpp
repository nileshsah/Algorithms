#include <bits/stdc++.h>
#define ll int
#define get(a) scanf("%d", &a)
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

ll minW( ll n ) {
	if( n <= 0 )
		return 0;
	else return (n+1) + minW(n/2) + minW(n-(n/2)-1);
}


int main() {
	ll t; get(t);
	while(t--) {
		ll n, m;
		get(n); get(m);
		ll y = n + n*(n+1)/2;
		ll x = minW(n);
		
		ll ans = INT_MAX;
		FOR(i,x,y)
		  if( m - i >= 0 )
		  	ans = min( ans, m-i );
		
		if( ans == INT_MAX )
			cout << "-1\n";
		else
		 	cout << ans << endl;
	}
}
