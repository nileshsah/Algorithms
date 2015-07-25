#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
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
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;


#define MOD 1000000007

ll fact[1005] = {0};
ll invfact[1005] = {0};

ll modpow( ll, ll );

void precompute( ll n ) {
	fact[0] = 1;
	FOR(i,1,n)
	 fact[i] = ( fact[i-1]*i )%MOD;
	
	FOR(i,1,n)
	 invfact[i] = modpow( fact[i], MOD-2 );
}

ll k;

ll modpow( ll x, ll y ) {
	ll ans = 1;
	while(y) {
		if(y%2)
		 ans = ( ans * x )%MOD;
		y /= 2;
		x = ( x * x )%MOD;
	}
	return ans;
}

ll ans = 0;

ll rec( vector<ll> v, ll n ) {
		
	if( n == -1 )
	 return 0;
	 
	ll num = 1;
	FOR(j,0,k-1)
	 num = ( num*fact[ v[j] ] )%MOD;
	
	FOR(i,0,k-1) 
	  if( v[i] > 0 ) {
	     v[i]--; 
	   sort( all(v) );
	   rec( v, n-1 );
	 }
	 
	 
	 ll dem = modpow( num, MOD-2 );
	 
	 cout << ( fact[n+1]*dem )%MOD << "\n";
	 
	 ans = ( ans + fact[n+1]*dem )%MOD;
	
}

int main() {
	vector<ll> v;
	ll sum = 0; cin >> k;
	FOR(i,1,k)
	 { ll x; cin >> x; v.pb(x-1); sum += x-1; }
	
	precompute(k);
	sort( all(v) );
	
	rec( v, sum );
	
	cout << ans;
	
}
