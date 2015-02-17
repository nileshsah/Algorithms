#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) a >= 0 ? a : -a
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
using namespace std;

int main() {
	ll n;
	get(n);
	matrix v;
	vector<ll> lhs, rhs;
	
	FOR(i,0,n)  {
		ll x, y, z, w;
		vector<ll> t;
		get(x); get(y); get(z); get(w);
		t.pb(x); t.pb(y); t.pb(z); t.pb(w);
		v.pb(t);	
	}
	
	
	FOR(i,0,n)
	 FOR(j,0,n) {
	 	ll temp = v[i][0] + v[j][1];
	 	lhs.pb(temp);
	 	temp = -( v[i][2] + v[j][3] );
	 	rhs.pb(temp);
	 }
	 
	 sort( all(lhs) );
	 sort( all(rhs) );
	 
	 ll ans = 0;
	 
	FOR(i,0,lhs.size()) {
		pair< vector<ll>::iterator, vector<ll>::iterator> b1, b2;
		b1 = equal_range( all(rhs) , lhs[i] );
		b2 = equal_range( all(lhs) , lhs[i] );
		
		ans += (b1.second - b1.first)*(b2.second - b2.first);
		i = b2.second - lhs.begin() - 1;
	}

	
	printf("%ld", ans );
	
}
