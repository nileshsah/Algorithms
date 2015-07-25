#include <bits/stdc++.h>
#define ll long
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

vector<ll> prime;
ll ptr[1000005] = {0};
ll arr[10000005] = {0};
bool mark[10000005] = {0};

void sieve( ll n ) {
	FOR(i,2,n)
	 if( !mark[i] ) {
	 	prime.pb(i);
	  for( ll k = i; k <= n; k += i )
	   ptr[prime.size()] += arr[k], mark[k] = 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	ll n, maxx = 0; cin >> n;
	FOR(i,1,n)
	 { ll x; cin >> x; arr[x]++; maxx = max(maxx,x); }
	sieve(maxx);
	
	FOR(i,1,prime.size()+1)
	 ptr[i] += ptr[i-1];
	 
	ll m; cin >> m;
	while(m--) {
		ll x, y;
		cin >> x >> y;
		ll l = lower_bound( all(prime), x ) - prime.begin() ;
		ll u = upper_bound( all(prime), y ) - prime.begin() ;

//		debug(l); debug(u);
	
		cout << ptr[u] - ptr[l] << "\n";	
				
	}
}
