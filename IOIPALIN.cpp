#include <bits/stdc++.h>
#define ll int
#define get(a) scanf("%d", &a);
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define max(a,b) ( (a > b) ? a : b )
#define min(a,b) ( (a < b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<long> >
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

int main() {
	INPFILE;
	ll n; get(n);
	char s[7000];
	scanf("%s", &s);
		
	string str(s);

	static short dp[2][6101] = {0};
	
	for( int i = 0; i <= str.size(); i++ )
		for( int x = str.size(), j = 0; j <= str.size(); j++, x-- ) {
			if( i == 0 || j == 0 )
				{ dp[i%2][j] = 0; continue; }
			if( str[i-1] == str[x-1] )
				dp[i%2][j] = 1 + dp[(i-1)%2][j-1];
			else
				dp[i%2][j] = max( dp[(i-1)%2][j] , dp[i%2][j-1] );
		}
	
	printf("%d", n - dp[str.size()%2][str.size()]);
}
