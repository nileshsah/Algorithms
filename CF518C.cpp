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
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

int main() {
//	INPFILE;
	ll n, m, k;
	cin >> n >> m >> k;
	
	ll arr[100005] = {0};
	ll order[100005] = {0};
	ll ans = 0;
	
	
	FOR(i,1,n) {
	 cin >> arr[i];
	 order[arr[i]] = i;
	}
	
	FOR(i,1,m) {
		ll x; cin >> x;
		ans += (order[x]-1)/k;
		ans++;
		
		cout << "A: " << ans << endl;
		
		if( order[x] != 1 ) {
			ll p = order[x]-1;
			order[arr[p]]++;
			order[x]--;
			swap( arr[p], arr[p+1] );
		}
	}
	
	cout << ans;
	
	
	
}
