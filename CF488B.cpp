#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define DEBUG(x) cout << "[DEBUG]" << #x << " " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

int main() {
	ll n; cin >> n;
	
	if( n == 0 ) {
		printf("YES\n1\n1\n3\n3\n");
		return 0;
	}
	
	if( n == 1 ) {
		ll x;
		cin >> x;
		
		printf("YES\n");
		cout << 2*x << '\n' << 2*x << '\n' << 3*x;
		return 0;
	}
	
	vector<ll> v;
	FOR(i,1,n)
	 { ll x; cin >> x; v.pb(x); }
	sort( all(v) );
	
	if( n == 2 ) {
		if( v[0] == v[1] )
		 { cout << "YES\n" << 3*v[0] << "\n" << 3*v[0]; return 0; }
		if( v[1] == 3*v[0] )
		 { cout << "YES\n" << v[0] <<  "\n" << v[1]; return 0; }
		if( 2*v[0] == v[1] )
		 { cout << "YES\n" << v[1] << "\n" << 3*v[0]; return 0; }
		if( 3*v[0] == 2*v[1] && v[0]%2 == 0 && v[1]%3 == 0 )
		 { cout << "YES\n" << v[0]/2 << "\n" << v[0]; return 0; }
	}
	
	if( n == 3 ) {
		if( v[0] == v[1] && 3*v[0] == v[2] )
		 { cout << "YES\n" << 3*v[0]; return 0; }
		if( 3*v[0] == v[1] && v[1] == v[2] )
		 { cout << "YES\n" << v[0]; return 0; }
		if( 2*v[0] == v[1] && v[1] == v[2] )
		 { cout << "YES\n" << 3*v[0]; return 0; }
		if( 2*v[0] == v[1] && 3*v[0] == v[2] )
		 { cout << "YES\n" << 2*v[0]; return 0; }
		if( v[0]%2 == 0 && v[2]%3 == 0 && v[0] == v[1] && 3*v[0] == 2*v[2] )
		 { cout << "YES\n" << v[0]/2; return 0; }
	}
	
	if( n == 4 ) {
		if( v[0] == v[1] && v[2] == v[3] && 3*v[0] == v[2] )
		 { cout << "YES"; return 0; }
		if( 2*v[0] == v[1] && v[1] == v[2] && 3*v[0] == v[3] )
		 { cout << "YES"; return 0; }
	}
	
	cout << "NO";
	
	
	
	
	
	
	
}
