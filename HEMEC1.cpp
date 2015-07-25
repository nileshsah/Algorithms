#include <bits/stdc++.h>
#define ll long long
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

ll fact[1000005] = {0};


int main() {
	ll t; cin >> t;

	fact[0] = 1;
	FOR(i,1,1000003)
	 fact[i] = ( fact[i-1]*i )%1000003;
	 
	while(t--) {
		ll x, n;
		cin >> n >> x;
		
		x %= 1000003;
		
		if( n >= 1000003 )
		 cout << "0\n";
		else
		 cout << ( fact[n]*x )%1000003 << "\n";
	
	}
}
