#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
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

ll lcs( ll *X, ll *Y, ll m, ll n )
{
   if (m == 0 || n == 0)
     return 0;
   if (X[m-1] == Y[n-1])
     return 1 + lcs(X, Y, m-1, n-1);
   else
     return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}


int LCS( vector<long> a, vector<long> b ) {
	vector< vector<long> > dp( a.size()+1, vector<long>( a.size()+1, 0 ) );
	for( int i = 0; i <= a.size(); i++ )
		for( int j = 0; j <= b.size(); j++ ) {
			if( i == 0 || j == 0 )
			  { dp[i][j] = 0; continue; }
			else if( a[i-1] == b[j-1] )
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
		}
	return dp[a.size()][b.size()];			
}

int main() {
	ll t;
	get(t);
	
	while(t--) {
		ll n; get(n);
		vector<long> x(n), y(n);
		rep(n)
		 get(x[i]);
		rep(n)
		 get(y[i]);	
		 
		cout << LCS(x,y) << endl;	 
	}
	
}
