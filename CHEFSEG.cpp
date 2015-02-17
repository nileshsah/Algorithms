#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define get(a) scanf("%lld", &a)
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for(vector< pair<ll,ll> >::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set< pair< ll, pair<ll,ll> > >::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<ll> >
#define MOD 10000007
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;


int main() {
	ll t;
	get(t);
	
	while(t--) {
		ll x, y;
		get(x); get(y);
		
		ll q = log2(y);
		ll p = pow(2,q);
		
		double val1 = double(x)/double( p*2 );
		double d = x/double(p);
		double val2 = d*( y - p );
		
		//cout << " VAL: " << val1;
		//cout << " \nVAL2: " << val2 << endl;
		
		printf("%lf\n", val1+val2);
	}
}
