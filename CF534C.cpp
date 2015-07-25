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

int main() {
	ll n, a;
	cin >> n >> a;
	vector<ll> v;
	ll sum = 0;
	
	FOR(i,1,n)
	 { ll x; cin >> x; v.pb(x); sum += x; }
	
	repVector(v) {
		ll x = sum - (*it);
		ll y = max(0LL,a-x-1);
		ll z = max(0LL, (*it) - ( a - n + 1 ) );
		cout << y+z <<  " ";
	}
	
}
