#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) a >= 0 ? a : -a
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

void vec( vector<ll> ans ) {
	if( !ans.empty() )
  FOR(i,0,ans.size()-1)
	printf("%ld ", ans[i]);
  printf("\n");
}

ll dp[105][10000] = {0};
int keep[105][10000]= {0};

vector<ll> ans;



	
int main() {
	ll t; get(t);
	while(t--) {
		ll n, m, sum = 0;
		get(n); get(m);
		vector<ll> v(n+1,0);
		
		rep(n) { get(v[i]); sum += v[i]; }
		
		sort( all(v) );
		
		memset( dp, 0, sizeof dp );
		memset( keep, 0, sizeof keep );
		
		FOR(i,1,n)
		 FOR(j,1,m) {
		  if( v[i] <= j && ( dp[i-1][j-v[i]] + v[i] >= dp[i-1][j] ) )
		   { dp[i][j] = dp[i-1][j-v[i]] + v[i]; keep[i][j] = 1; }
		  else
		   { dp[i][j] = dp[i-1][j]; keep[i][j] = 0; }
		}
		   
	/*	FOR(i,0,n) {
		 FOR(j,0,m)
		  cout << keep[i][j] << " ";
		cout << endl;
	  }
	  
	  FOR(i,0,n) {
		 FOR(j,0,m)
		  cout << dp[i][j] << " ";
		cout << endl;
	  }
	  */
		
		ll ans = dp[n][m];
		
	//	cout << " ANS: " << ans << endl;
	
		if( sum - ans > m )
		 { printf("NO\n"); continue; }
		
		vector<ll> sack, v1;
		
		ll i = n, w = m;
		
		while( i > 0 ) {
			if( keep[i][w] )
			  { w = w - v[i]; sack.pb(v[i]); }
			i--;
		}
		
	//	vec( sack );
		sort( all(sack) );
		
		ll ptr = 0;
		
		FOR(i,1,n)
		 if( ptr < sack.size() && sack[ptr] == v[i] )
		 	 { ptr++; continue; }
		 else
		  	v1.pb(v[i]);
		  	
		 sort( all(v1) );
		  	
		  printf("YES\n");
		  if( v1.empty() && !sack.empty() )
		  	{ vec( v1 ); vec( sack ); }
		  else if( sack.empty() )
		   { vec( sack ); vec( v1 ); }
		 else if( v1[0] < sack[0] )
		   { vec( v1 ); vec( sack ); }
		 else
		   { vec( sack ); vec( v1 ); }
		
		
		
	}
}
