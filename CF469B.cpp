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
	ll p, q, l ,r;
	cin >> p >> q >> l >> r;
	vector< pair<ll,ll> > v, idx;
	
	rep(p)
	 { ll x, y; cin >> x >> y; v.pb( mp(x,y) ); }
	rep(q)
	 { ll x, y; cin >> x >> y; idx.pb( mp(x,y) ); }
	 	 
	 ll ans = 0;
	
	FOR(i,l,r) {
		bool flag = 0;
	 FOR(j,0,v.size()-1) {
	  FOR(k,0,idx.size()-1)
	   if( idx[k].F + i >= v[j].F && idx[k].F+i <= v[j].S )
	    { ans++; flag = 1; break; }
	  else if( idx[k].S + i >= v[j].F && idx[k].S+i <= v[j].S )
	    { ans++; flag = 1; break; }
	  if( flag )
	  	break;
	 }
	}
	
	cout << ans;
}
