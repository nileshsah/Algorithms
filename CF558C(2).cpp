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
	ll n; cin >> n;
	ll val[100005] = {0};
	ll steps[100005] = {0};
	FOR(i,1,n) {
		ll x; cin >> x;
		queue< pair<ll,ll> > q;
		q.push( mp(x,0) );
		bool explore[100005] = {0};

		while(!q.empty()) {
			ll x = q.front().F;
			ll y = q.front().S;
			q.pop();
			if( x > 100000 || explore[x]  )
			 continue;
			explore[x] = 1;
			steps[x] += y;
			val[x]++;
			
			q.push( mp(x*2,y+1) );
			q.push( mp(x/2,y+1) );
		}
	}
	
	ll ans = LONG_MAX;
	FOR(i,1,100000)
	 if( val[i] == n )
	  ans = min(ans,steps[i]);
	cout << ans;
}
