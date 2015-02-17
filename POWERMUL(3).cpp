#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define get(a) scanf("%lld", &a)
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for(vector< pair<ll,ll> >::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set< pair< ll, pair<ll,ll> > >::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

ll fast_pow( ll a, ll b, ll mod ) {
	if( b == 0 )
		return 1;
	if( b == 1 )
		return a;
	
	if( b%2 == 0 ) {
		ll val = fast_pow( a, b/2, mod );
		return (val*val)%mod;
	}
	else if( b%2 != 0 ) {
		ll val = fast_pow( a, (b-1), mod );
		return (a*val)%mod;
	}
	
}



ll f[10+5] = {0};

int main() {
	
	ll f[7] = {0};
	f[1] = 1;
	
	FOR(i,2,5)
	  f[i] = f[i-1]*fast_pow( i, i , LONG_MAX );
	  
	ll t;
	get(t);
	
	while(t--) {
		ll n, m, q;
		get(n); get(m); get(q);
				
     	while(q--) {
			ll r; get(r);
		
		if( n <= 5 ) {
			printf("%lld\n", ( f[n]/( f[r]*f[n-r] ) ) % m );
			continue;
		}
			
			
			ll num[100000+5] = {0};
			ll den[100000+5] = {0};
	
			
			FOR(i,1,min(r,n-r)) {
				den[i] = min(r,n-r)-1;
				if( i == min(r,n-r) )
					den[i]++;
				num[n+1-i] = n+1-i;
			}	
	
			
			FOR(i,1,n)
			 cout << " " << i;
			cout << endl;
			FOR(i,1,n)
			  cout << " " << num[i];
			cout << endl;
			FOR(i,1,n)
			  cout << " " << den[i];
			cout << "\n\n\n";
			
			
			
			ll st = max(r,n-r)+1;
			
			for( ll i = min(r,n-r); i >= 2; i-- ) {
				ll j = 0;
				while( num[i] < den[i] ) {
					ll ptr = i*ceil(double(st)/i) + j;
					ll pw = 0, tptr = ptr;
					while( ptr%i == 0 )
					  { pw++; ptr /= i; }
					num[i] += pw*num[tptr];
					num[ptr] += num[tptr];
					num[tptr] = 0;
					j++;
				}
				//cout << " NEW: " << i << " " << num[i] << endl;
				num[i] -= den[i]; den[i] = 0;
			}
			
			/*FOR(i,1,n)
			 cout << " " << i;
			cout << endl;
			FOR(i,1,n)
			  cout << " " << num[i];
			cout << endl;
			FOR(i,1,n)
			  cout << " " << den[i];
			cout << "\n\n\n";
			*/
			
			long long unsigned ans = 1;
			
			FOR(i,2,n)
			  { ans *= fast_pow( i, num[i], m ); ans %= m; }
				
			printf("%llu\n", ans);
			
			
		}
	}
}
