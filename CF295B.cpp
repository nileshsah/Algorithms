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

ll dist[505][505];
ll d[505][505], n;
bool check[505] = {0};



int main() {
	cin >> n;
	FOR(i,1,n)
	 FOR(j,1,n) {
	  cin >> d[i][j];
	}
	
	vector<ll> v;
	FOR(i,1,n)
	 { ll x; cin >> x; v.pb(x); }
	reverse( all(v) );
	
	ll ans[505] = {0};
	
	FOR(q,0,n-1) {
	   ll k = v[q];
	   FOR(i,1,n)
	    FOR(j,1,n)
	     d[i][j] = min( d[i][j], d[i][k]+d[k][j] );
	   FOR(i,0,q)
	    FOR(j,0,q)
	     if( i != j )
	     ans[q] += d[v[i]][v[j]];
	}
	
	ROF(i,n-1,0)
	 cout << ans[i] << " ";
	
		
}
