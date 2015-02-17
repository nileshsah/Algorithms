#include <bits/stdc++.h>
#include <cstdio>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<int>::iterator it = v.begin(); it != v.end(); it++ )
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

vector<ll> v;
ll ans = INT_MAX;

void rec( ll k, ll prev, ll c = 0 ) {
	//cout << " REC: " << k << " P: " << prev << " " << c << endl;
	if( k >= v.size()-1 && prev < v[k] )
	  { ans = min( ans, c+1 ); return; }
	  
	FOR(i,prev,v[k])
	  if( i == prev )
		rec( k+1, v[k] - i, c+1 );
	  else
	    rec( k+1, v[k] - i, c+2 );
}

int main() {
	ll t;
	get(t);
	
	while(t--) {
		ans = INT_MAX;
		v.clear();
		ll n; get(n);		
		rep(n) { ll x; get(x); v.pb(x); }
		
	   FOR(i,1,v[0])
		rec(1,i,1);
	   cout << ans << endl;
		 
	}
}
