#include <bits/stdc++.h>
#define ll long long
#define get(a) cin >> a;
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

int main() {
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	
	ll mish = max( 3*a/10, a - a*c/250 );
	ll vas = max( 3*b/10, b - b*d/250 );
	
	if( mish > vas )
	 cout << "Misha";
	else if( vas > mish )
	 cout << "Vasya";
	else
	 cout << "Tie";
}
