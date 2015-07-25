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

int main() {
	ll n; cin >> n;
	ll digits = 0, num = n;
	while(num) {
		num /= 10;
		digits++;
	}
	
//	debug(digits);


	
	ll ans = 0;
	FOR(i,1,digits-1) {
	 ans += 9*pow(10,i-1)*i;
//	 debug(ans);
	}
	
	ll val = (ll)pow(10,digits-1);
	ans += (n - val + 1)*digits;
	
	cout << ans;
	
}
