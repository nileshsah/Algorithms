#include <bits/stdc++.h>
#define ll int
#define get(a) scanf("%ld", &a);
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

vector<ll> v;
ll arr[2000005] = {0};
bool mark[2000005] = {0};

int main() {
	BOOST;
	ll n; cin >> n;
	FOR(i,1,n)
	 { ll x; cin >> x; v.pb(x); mark[x] = 1;  }
	
	ll ans = 0, j = 0;
//	sort( all(v) );
	
	FOR(i,1,2000000)
	 arr[i] = max( arr[i-1], mark[i-1]*(i-1) );
	
	FOR(i,0,n-1)
	 for( ll k = 2*v[i]; ; k += v[i] ) {
//	 	debug(v[i]); debug(k); debug(arr[k]);
	   ans = max( ans, arr[k]%v[i] );
	   if( k > v[n-1] ) break;
	 }
	 
	 cout << ans;
}

