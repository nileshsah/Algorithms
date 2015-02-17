#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
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

string a;

ll dp[200][200] = {0};

ll mul( ll x, ll y ) {
	if( x == y )
		return a[x] - '0';
	
	if( dp[x][y] != -1 )
		return dp[x][y];
	
	ll maxx = INT_MIN;
	ll val = a[x]-'0';
	
	FOR(i,x+1,y)
		if( a[i] == '+' )
			maxx = max( maxx, mul(x,i-1) + mul(i+1,y) );
		else if( a[i] == '*' ) 
			maxx = max( maxx, mul(x,i-1)*mul(i+1,y) );
	
//	printf(" MAX-REC: %ld %ld = %ld\n", x, y, maxx);

	 dp[x][y] = maxx; 
	 return maxx; 	
}

ll mul2( ll x, ll y ) {
	if( x == y )
		return a[x] - '0';
	
	if( dp[x][y] != -1 )
		return dp[x][y];
	
	ll mix = INT_MAX;
	
	FOR(i,x+1,y)
		if( a[i] == '+' )
			mix = min( mix, mul2(x,i-1) + mul2(i+1,y) );
		else if( a[i] == '*' ) 
			mix = min( mix, mul2(x,i-1)*mul2(i+1,y) );
	
//	printf(" MIN-REC: %ld %ld = %ld\n", x, y, mix);
	 
	 dp[x][y] = mix; 
	 return mix; 	
}


int main() {
//	INPFILE;
	ll t; get(t);
	while(t--) {
		char str[200];
		scanf("%s", &str);
		
		a = string(str);
		memset( dp, -1, sizeof dp );
		ll m = mul(0,a.size()-1);
		memset( dp, -1, sizeof dp );
		ll s = mul2(0,a.size()-1);
		
		printf("%lld %lld\n", m, s );	
		
	}
}
