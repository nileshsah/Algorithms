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

vector<ll> boys, girls;
ll n, k;

ll search( ll start, ll end, ll val ) {
	ll mid = ( start + end )/2;
	
	if( start > end )
	  return max(0LL,start);
	if( abs( val - girls[mid] ) <= k )
	 return search( start, mid-1, val );
	else if( val < girls[mid] )
	 return search( start, mid-1, val );
	else
	 return search( mid+1, end, val );
}

int main() {
//	ll n, k;
	cin >> n >> k;
	FOR(i,1,n)
	 { ll x; cin >> x; boys.pb(x); }
	FOR(i,1,n)
	 { ll x; cin >> x; girls.pb(x); }
	ll ans = 0, y = 0;
	sort( all(boys) );
	sort( all(girls) );
	
	FOR(i,0,n-1) {
	  ll y  = search( 0, girls.size()-1, boys[i] );
	  y = max(0LL,y); y = min(y,(ll)girls.size()-1);
	  if( abs( boys[i] - girls[y] ) <= k ) {
	  	ans++;
	  	girls.erase(y+girls.begin());
	  	y--;
	  }
	}
	 
	cout << ans;
}
