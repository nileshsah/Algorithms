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

int main() {
	ll n; cin >> n;
	ll size = 1, sum = 0;
	ll arr[200005] = {0};
	stack<ll> s;
	s.push(0);
	while(n--) {
		ll t; cin >> t;
		if( t == 1 ) {
			ll x, a;
			cin >> x >> a;
			arr[x] += a;
			sum += x*a;
		}
		else if( t == 2 ) {
			ll x; cin >> x;
			sum += x; 
			s.push(x);
		}
		else if ( t == 3 ) {
			sum -= s.top();
			sum -= arr[s.size()];
			arr[s.size()-1] += arr[s.size()];
			arr[s.size()] = 0;
			s.pop();
		}
		double ans = 1.0*sum/s.size();
		printf("%0.6lf\n", ans);
	}
}
