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
#define MOD 1000000007
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

bool mark[305][305] = {0};
vector< pair<ll,ll> > v;
ll n, m;

inline bool check( ll x, ll y ) {
	if( x > n || y > m || x <= 0 || y <= 0 )
		return 0;
	return !mark[x][y];
}

pair<ll,ll> dfs( ll x, ll y, ll k ) {
	if( !mark[x][y] ) {
//	   cout << x << " " << y << endl; 
	   v.pb( mp(x,y) ); 
	   k--; mark[x][y] = 1;
    }

	if( k == 0 )
	 return mp(x,y);
	 
	if( check(x+1,y) )
	  return dfs( x+1, y, k );
	else if( check(x-1,y) )
	  return dfs( x-1, y, k);
	else if( check(x,y+1) )
	  return dfs( x, y+1, k );	
}


int main() {
	ll k;
	cin >> n >> m >> k;
	
	ll div = (n*m)/k;
	ll val = n*m;
	pair<ll,ll> last = mp(1,1);
	
	FOR(i,1,k) {
	  v.clear();
	  ll p = div;
	   if( i == k )
		 p = val;
	   last = dfs( last.F, last.S, p );
	   cout << p << " ";
	   repVector(v)
	    cout << it->F << " " << it->S << " ";
	   cout << "\n";
	   val -= p;
	}
	
}
