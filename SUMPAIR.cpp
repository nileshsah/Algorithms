#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
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
	ll t; cin >> t;
	while(t--) {
		ll n, d;
		cin >> n >> d;
		vector<ll> v;
		FOR(i,1,n)
		 { ll x; cin >> x; v.pb(x); }
		
		sort( all(v) );
		bool explore[100005] = {0};
		ll ans = 0;
		ROF(i,n-2,0)
		 if( !explore[i+1] && v[i+1] < v[i]+d )
		  { explore[i] = explore[i+1] = 1; ans += v[i]+v[i+1]; }
		
		cout << ans << "\n";
		 
	}
}
