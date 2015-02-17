#include <bits/stdc++.h>
#define ll long long
#define get(a) cin >> a;
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<string>::iterator it = s.begin(); it != s.end(); it++ )
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
#define INF LONG_MAX
using namespace std;

int main() {
	ll t; get(t);
	while(t--) {
		ll n; get(n);
		vector<ll> v;
		
		while( n > 0 ) {
		  if( n%7 == 0 )
		  	{ v.pb(7);  n /= 7; n--; }
		  else
		  	{ v.pb(n%7); n /= 7; }
		}
		
		reverse( all(v) );
		string c = "ddhapusv";
		
		FOR(i,0,v.size()-1) 
		 printf("%c", c[ v[i] ]);
		printf("\n");
	}
}
