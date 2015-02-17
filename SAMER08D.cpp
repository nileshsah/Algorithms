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
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

char a[1005], b[1005];
ll k, A, B;
ll dp[1005][1005] = {0};

ll mLCS( ll x, ll y, ll c) {
	if( x+c > A || y+c > B )
		return 0;
		
	if( dp[x][y] != -1 )
		return dp[x][y];

	ll val = 0;
	
	if( strncmp( a+x,b+y,c) == 0 )
		dp[x][y] = c + mLCS(x+c,y+c,1);

		dp[x][y] = max( dp[x][y], max(mLCS(x+1,y,k), mLCS(x,y+1,k) ) );
	
//	printf(" REC: %ld %ld [%ld] = %ld\n", x,y,c,dp[x][y]);
	
	return dp[x][y];
		
}

ll LCS() {
	
	for( ll i = k; i <= A; i++ )
	 for( ll j = k; j <= B; j++ ) {
	 	dp[i][j] = max( dp[i][j-1], dp[i-1][j] );
	 	
	 	FOR(t,0,i) {
	 	  if( t >= k )
	 	  	dp[i][j] = max( dp[i][j], dp[i-t][j-t] + t );
	 	  if( a[i-t] != b[j-t] ) break;
	 	}
	 	  
	 }
	 
	 return dp[A][B];	
}

int main() {
//	INPFILE;
	
	while(1) {
		get(k);
		
		if( k == 0 ) return 0;
		
		char s1[1005], s2[1005];
		scanf("%s%s", a+1, b+1);
		A = strlen(a+1); B = strlen(b+1);
		
		memset( dp, 0, sizeof dp );
		
		printf("%ld\n", LCS());
		
	}
}
