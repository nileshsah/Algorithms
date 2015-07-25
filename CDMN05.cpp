#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define DEBUG(x) cout << "[DEBUG]" << #x << " " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

ll dp[25][25] = {0};

bool board( ll n, ll m ) {
	
//	cout << "S: " << man << " - " << n << " x " << m << " = " << man << endl;

	if( n == 1 || m == 1 )
		return 1;
	
/*	if( dp[n][m][man] != -1 )
		return dp[n][m][man];
	if( dp[m][n][man] != -1 )
		return dp[n][m][man];
*/
	
	ll win = 0;
	bool flag = 0;
	
	FOR(i,1,n)
	 FOR(j,1,m) {
	 	win = 0;
	 	ll task = 0;
	 	
	 	if( i-1 >= 1 && j-1 >= 1 )
	 	  { win += board( i-1, j-1  ); task++; }
	 	if( i+1 <= n && j+1 <= m )
	 	  { win += board( n-i, m-j ); task++; }
	 	if( i+1 <= n &&  j-1 >= 1 )
	 	  { win += board( n-i,  j-1 ); task++; }
	 	if(  i-1 >= 1 && j+1 <= m )
	 	  { win += board( i-1, m-j  ); task++; }
	 	  
	 	cout << "WIN: "  << i << " x " << j << " = " << win << endl;
	 	if( ( task - win )%2 == 0  )
		   return 1;
	 }
	 
	 return 0;

}

int main() {
	memset( dp, -1, sizeof dp );
	ll t; get(t);
	while(t--) {
	   ll n, m;
	   get(n); get(m);
	   
	   if( board(n,m) )
	    cout << "Alice\n";
	   else
	    cout << "Bob\n";
		
	}
}
