#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <cstring>
#define ll int
#define get(a) scanf("%d", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define pb push_back
#define max(a,b) a > b ? a : b
using namespace std;



ll lcs( string str, string rev ) {
	static short dp[6101][6101] = {0};
	
	for( int i = 0; i <= str.size(); i++ )
		for( int j = 0; j <= rev.size(); j++ ) {
			if( i == 0 || j == 0 )
				{ dp[i][j] = 0; continue; }
			if( str[i-1] == rev[j-1] )
				dp[i][j] = 1 + dp[i-1][j-1];
			else
				dp[i][j] = max( dp[i-1][j] , dp[i][j-1] );
		}
	
	return dp[str.size()][rev.size()];
}
	
int main() {
	long t;
	get(t);
	
	while(t--) {
		char s[7000];
		scanf("%s", &s);
		string str(s);
		string rev;
		
						
		
		for( int i = str.size()-1; i >= 0; i-- )
			rev.pb(str[i]);
		
		ll gcc = lcs( str, rev);
		printf("%d\n", str.size() - gcc );
	}
}
