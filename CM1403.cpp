#include <bits/stdc++.h>
#include <cstdio>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) a >= 0 ? a : -a
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define L 2*r
#define R 2*r+1
using namespace std;

ll a, m, n;
ll ans = 0;

void rec( ll k, ll prev, vector<ll> v[] ) {
	//cout << " REC: " << k << " " << prev << endl;
	if( k == n )
	  { ans++; return; }
	  
	repVector( v[k] )
		if( *it - prev <= m )
			rec( k+1, *it,  v );
}

int main() {
	ll t;
	get(t);
	
	while(t--) {
		get(a); get(m);
		vector<ll> v;
		ans = 0;
		rep(a)
		 { ll x; get(x); v.pb(x); }
		 get(n);
		vector<ll> town[n];
		rep(n) {
		  ll x, y; get(x); get(y); 
		  FOR(j,x,y+1)
		  	town[i].pb(v[j]);
		}
		
	
		FOR(i,0,town[0].size())
			rec( 1, town[0][i], town );
		cout << ans << endl;
		
	}
}
