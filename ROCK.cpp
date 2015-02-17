#include <bits/stdc++.h>
#include <cstdio>
#define ll int
#define get(a) scanf("%d", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector< pair<ll,double> >::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set< pair< ll, pair<ll,ll> > >::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 10000007
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

ll dp[305][305] = {0};
string a;

ll rec( ll start, ll end ) {
	
	if( dp[start][end] != -1 ) return dp[start][end];
	ll val = 0;
	
	FOR(i,start,end) {
		if( a[i] == '0' )
			val--;
		else if( a[i] == '1' )
			val++;
	}

	if( val <= 0 ) val = 0;
	else val = end-start+1;
	
	if( val == 0 )
	 FOR(i,start+1,end)
	  val = max( val, rec(start,i-1) + rec(i,end) );

	 dp[start][end] = val;
	
//	cout << " REC: " << start << " " << end << " -> " << val << "\n";
	return val;
}


int main() {
	ll t;
	get(t);
	while(t--) {
		ll n; get(n);
		cin >> a;
		memset( dp, -1, sizeof dp );
		
		rec(0,n-1);
		printf("%d\n", dp[0][n-1]);
		
	}
}
