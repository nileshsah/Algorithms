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
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

ll dp[1000] = {0};

ll fact( ll x ) {
	if( x <= 0 )
		return 1;
	if( dp[x] != 0 )
		return dp[x];
	dp[x] = x*fact(x-1);
	return dp[x];
}

int main() {
//	INPFILE;
	string s;
	while( getline(cin,s) ) {
		ll arr[27] = {0}, len = 0;
		
		FOR(i,0,s.size()-1)
		  if( isalpha(s[i]) )
		  	{ arr[ tolower(s[i]) - 'a' ]++; len++; }
		
		ll ans = fact(len/2), c = 0;
		
		FOR(i,0,26) {
		  if( len%2 == 0 && arr[i]%2 )
			{ ans = 0; break; }
		  if( len%2 && arr[i]%2 )
		  	{ c++; if( c >= 2 )	{ ans = 0; break; } }
		  ans /= fact( arr[i]/2 );
		}
		
		printf("%lld\n", ans);
		
	}
}
