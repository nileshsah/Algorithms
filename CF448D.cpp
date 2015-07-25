#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
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
#define INPFILE freopen("input.in","r",stdin);
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

ll n, m, k;

bool check( ll x ) {
	ll count = 0;
	FOR(i,1,n)
	 count += min( m, (x-1)/i );
	return ( count < k );	 
}

ll search( ll start, ll end ) {
	ll mid = ( start + end )/2;
	
	if( start > end )
	 return start;
	if( check(mid) )
	 return search( mid+1, end );
	else
	 return search( start, mid-1 );
}

int main() {
	cin >> n >> m >> k;
	cout << search( 1, 25*10000000000 ) - 1;
}
