#include <bits/stdc++.h>
#include <cstdio>
#define ll int
#define get(a) scanf("%d", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define max(a,b) ( (a > b) ? a : b )
#define min(a,b) ( (a < b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<long long> >
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
using namespace std;

int main() {
	//	freopen("input.in", "r", stdin);
		
		ll t; get(t);
	while(t--) {
		ll N, T;
		get(N); get(T);
		ll n = N;
		vector< vector<int> > Time( n, vector<int>(n) );
		vector< vector<int> > risk( n, vector<int>(n) );
		
		FOR(i,0,N)
		 FOR(j,0,N)
		  get(Time[i][j]);
		
		FOR(i,0,N)
		 FOR(j,0,N)
		  get(risk[i][j]);
		
		matrix dp( T+1, vector<long long>(N,INT_MAX) );
		
		
		FOR(i,0,T+1)
		 dp[i][N-1] = 0;
		
		FOR(i,0,T+1)
		 FOR(j,0,N)
		  FOR(k,0,N)
			if( i - Time[j][k] >= 0 )
				dp[i][j] = min( risk[j][k] + dp[ i - Time[j][k] ][k], dp[i][j] );
				
		
		FOR(i,0,T+1) {
		 FOR(j,0,N)
		   cout << dp[i][j] << " ";
		 cout << endl;
		}
		
				
		
		
		ll t = T;
		while( t >= 0 && dp[T][0] == dp[t][0] ) t--;
		
		if( dp[T][0] >= INT_MAX )
		  printf("-1\n");
		else
		  printf("%lld %lld\n", dp[T][0], t+1);
		
		
		  	
		
	}
}



