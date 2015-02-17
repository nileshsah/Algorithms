#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

int main() {
	ll t; get(t);
	while(t--) {
		ll n, k;
		get(n); get(k);
		char str[n+5];
		scanf("%s", str+1);
	
		ll mx = 0, dist = 0;
		
		FOR(i,1,n)
		 if( str[i] == '.' )
		  dist = 0;
		 else if( str[i] == '#' )
		 	{ dist++; mx = max( mx, dist ); }
		
		if( mx >= k )
			printf("NO\n");
		else
			printf("YES\n");
		
	}
}
