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

ll a[100005] = {0};
ll dp[100005] = {0};


int main() {
	ll n; cin >> n;	
	set<ll> s;
	FOR(i,1,n) {
		ll x; cin >> x;
		s.insert(x);
		a[x]++;
	}
	
	dp[1] = a[1]; dp[0] = 0;
	
	FOR(i,2,*s.rbegin())
	    dp[i] = max( dp[i-1], dp[i-2] + a[i]*i );

	
	cout << dp[*s.rbegin()];
}
