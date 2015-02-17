#include <bits/stdc++.h>
#include <cstdio>
#define ll int
#define get(a) scanf("%d", &a)
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for(vector<int>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) a >= 0 ? a : -a
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define L 2*r
#define R 2*r+1
using namespace std;

int dp[2000+5][2000+5];
int main() {
	ll t;
	get(t);
	
	while(t--) {
		string a, b;
		cin >> a >> b;
		a = " " + a;
		b = " " + b;
		
		memset( dp, 0, sizeof dp );
		
		FOR(i,0,b.size())
		 dp[0][i] = i;
		FOR(i,0,a.size())
		 dp[i][0] = i;
		
		FOR(i,1,a.size())
		 FOR(j,1,b.size()) {
		 	ll c = 1;
		 	if( b[j] == a[i] )
		 	 c = 0;
		 	dp[i][j] = min( dp[i-1][j-1]+c, min( dp[i-1][j]+1, dp[i][j-1]+1 ) );
		 }
		
		printf("%d\n", dp[a.size()-1][b.size()-1] );
		 
		
	}
}
