#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
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
#define MOD 1000000007
using namespace std;

ll arr[100005] = {0};

int main() {	
	
	arr[1] = 1;
	ll val = 1;
	
	FOR(i,2,100000) {
	 arr[i] = ( val + arr[i-1] + arr[i-1] )%MOD;
	 val *= 2; val %= MOD;
	}
		
	
	ll t, c = 1; get(t);
	while(t--) {
		ll n; get(n);
		printf("Case %lld: %lld\n", c++, arr[n]);
	}
}
