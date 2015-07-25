#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
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
using namespace std;

int main() {
	ll n; cin >> n;
	ll ptr = 0;
	pair<ll,pair<ll,ll> > v = mp(INT_MAX,mp(INT_MAX,INT_MAX));
	
	while( n - 7*ptr >= 0 ) {
	 if( ( n - 7*ptr )%4 == 0 ) {
	   ll ltr = (n-7*ptr)/4;
	   v = min( v, mp(ltr+ptr,mp(ptr,ltr)) );
	 }
	  ptr++;
	}
	
	if( v.F == INT_MAX )
	 { cout << "-1"; return 0; }
	
	FOR(i,1,v.S.S)
	 cout << "4";
	FOR(i,1,v.S.F)
	 cout << "7";
}
