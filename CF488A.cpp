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
#define DEBUG(x) cout << "[DEBUG]" << #x << " " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

bool check( ll n ) {
	n = abs(n);
	
	while( n!= 0 ) {
	   if( n%10 == 8 )
	   	return 1;
	   n /= 10;
	}
	
	return 0;
}

int main() {
	ll n; cin >> n;

	ll ans = 0;
	FOR(i,n+1,LLONG_MAX) {
	  ans++;
	  if( check(i) )
	  	break;
	 }
	 
	 cout << ans;
	
}
