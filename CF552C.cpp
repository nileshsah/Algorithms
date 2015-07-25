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

bool rec( ll w, ll m ) {
//	debug(m);
	bool ret = 0;
	if( m <= 0 )
	 return 1;
	 
	if( ( m - 1 )%w == 0 )
	 ret |= rec( w, (m-1)/w );
	if( !ret && ( m + 1 )%w == 0 )
	 ret |= rec( w, (m+1)/w );
	if( !ret && m%w == 0 )
	 ret |= rec( w, m/w );
	
	return ret;
}

int main() {
	ll w, m;
	cin >> w >> m;
	
	if(rec(w,m))
	 cout << "YES";
	else
	 cout << "NO";
	
}
