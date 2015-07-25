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

pair<double,double> solve( double a, double b, double d ) {
	vector<double> v;
	v.pb( (a-d)*(b-d) );
	v.pb( (a-d)*(b+d) );
	v.pb( (a+d)*(b-d) );
	v.pb( (a+d)*(b+d) );
	sort( all(v) );
	return mp( v[0], v[3] );
}


int main() {
	double a, b, c, d;
	cin >> a >> b >> c >> d;
	
	double low = 0, high = pow(10,10), mid;
	
	FOR(i,1,500) {
		mid = ( low + high )*0.5;
		auto p = solve( a, d, mid );
		auto q = solve( b, c, mid );
		
		if( p.S < q.F || p.F > q.S )
		  low = mid;
		else
		  high = mid;
	}
	
	printf("%0.9lf", mid);
		
}
