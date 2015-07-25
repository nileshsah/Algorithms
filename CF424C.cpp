#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( auto it = s.begin(); it != s.end(); it++ )
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
using namespace std;

ll arr[1000005] = {0};

int main() {
	ll n; cin >> n;
	ll ans = 0;
	FOR(i,1,n)
	 { ll x; cin >> x; ans ^= x; }
	
	FOR(i,2,n)
	 FOR(j,1,i-1)
	  arr[j] = ( arr[j] + (long long)ceil(1.0*(n-j+1)/i) )%2;
	
	FOR(i,1,n)
	 ans ^= arr[i]*i;
	
	cout << ans;
	  
}
