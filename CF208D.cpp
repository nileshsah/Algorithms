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
#define MOD 1000000009
using namespace std;

vector<ll> v;
vector<ll> prize;
ll ans[5] = {0};


int main() {
	ll n; cin >> n;
	FOR(i,1,n)
	 { ll x; cin >> x; v.pb(x); }
	FOR(i,1,5)
	 { ll x; cin >> x; prize.pb(x); }
	
	ll sum = 0;
	
	FOR(i,0,n-1) {
		sum += v[i];
	 ROF(j,4,0)
	  if( sum/prize[j] > 0 )
	   { ans[j] += sum/prize[j]; sum %= prize[j]; }
	}
	
	FOR(i,0,4)
	 cout << ans[i] << " ";
	cout << "\n" << sum;
				
}
