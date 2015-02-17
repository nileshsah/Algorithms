#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) a >= 0 ? a : -a
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
using namespace std;

bool m[7000000] = {0};

int main() {
	vector<ll> v;
    v.pb(0);
	m[0] = 1;
	
	FOR( i,1, 500000+1 ) {
		ll a = v[i-1] - i;
		if( a < 0 || m[a] == 1 )
		 { v.pb( v[i-1] + i ); m[ v[i-1] + i ] = 1; }
		else
		 { v.pb(a); m[a] = 1; }
	}
	
	while(1) {
		ll n;
		get(n);
		
		if( n == -1 )
			break;
		
		printf("%lld\n", v[n]);
		
		
	}
}
