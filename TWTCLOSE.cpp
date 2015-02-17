#include <bits/stdc++.h>
#define ll int
#define get(a) scanf("%d", &a)
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
	ll n, m;
	get(n); get(m);
	bool mark[1001] = {0};
	ll ans = 0;
	
	rep(m) {
		char str[100];
		scanf("%s", &str);
		string s(str);
		
		if( s == "CLICK" ) {
			ll x; get(x);
			if( mark[x] )
			  ans--;
			else
			 ans++;
			mark[x] = !mark[x];
		}
		else if( s == "CLOSEALL" ) {
			memset( mark, 0, n+1 );
			ans = 0;			
		}
		
		printf("%d\n", ans);

	}
	
}
