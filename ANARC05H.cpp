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

ll N;
ll sum[30] = {0};
ll dp[30][9*26] = {0};

ll rec( ll r, ll val ) {
//	cout << " REC: " << r << " " << val << endl;
	if( r > N )
		return 0;
	
	if( dp[r][val] != -1 )
		return dp[r][val];
		
	ll ans = 0;
	
	FOR(i,r+1,N-1)
	  if( ( sum[i] - sum[r] <= sum[N] - sum[i] ) && ( sum[i] - sum[r] >= val )   )
			ans += 1 + rec( i, sum[i] - sum[r] );
	
	dp[r][val] = ans;
	return ans;			
				
}

int main() {
//	INPFILE;
	ll c = 1;
	while(1) {
		char str[1000];
		scanf("%s", &str);
		
		if( str[0] == 'b' )
			return 0;
			
		N = strlen(str);
		memset( sum, 0, sizeof sum );
		memset( dp, -1, sizeof dp );
		
		
		FOR(i,0,strlen(str)-1) {
		   sum[i+1] = sum[i] + str[i] - '0';	
		}
		
		
		printf("%ld. %ld\n",c++,rec(0,0)+1);
				
			
	}
}
