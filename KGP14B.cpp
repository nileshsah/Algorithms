#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define max(a,b) ( (a > b) ? a : b )
#define min(a,b) ( (a < b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

ll dp[1005][1005] = {0};
string a, b;

ll LCS() {
	
	memset( dp, 0, sizeof dp );
	
	FOR(i,0,a.size()+1)
	 FOR(j,0,b.size()+1)
	 	if( i == 0 || j == 0 )
	 		continue;
	 	else if( a[i-1] == b[j-1] )
	 		dp[i][j] = dp[i-1][j-1] + 1;
	 	else
	 		dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
	return dp[a.size()][b.size()];
	
}

int main() {
//	INPFILE;
	ll t, c= 1; get(t);
	while(t--) {
		ll x, y;
		char s1[2000], s2[2000];
		get(x); get(y);
		scanf("%s %s", &s1, &s2);
		a = string(s1);
		b = string(s2);
		
		printf("Case %ld: %ld\n", c++, x+y-LCS());
	}
}
