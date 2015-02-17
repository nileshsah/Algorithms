#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define foo(a,b,c) mp( mp(a,b), c )
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;


char temp[1000];

int main() {
//	ios_base::sync_with_stdio(0);
	
	ll t; get(t);
	while(t--) {
		ll n; get(n);
		vector<string> v;
		
		FOR(i,1,n) {
			scanf("%s", &temp);
			v.pb(string(temp));
		}
		
//		sort( all(v) );
		
		scanf("%s", &temp);
		
		if( binary_search( all(v), string(temp) ) )
			printf("yes\n");
		else
		 	printf("no\n");
	}
}
