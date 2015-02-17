#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define MOD 1000000007
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

ll x[100005] = {0}, y[100005] = {0};
ll dp[200005] = {0};


int main() {
//	INPFILE;
	ll n; get(n);
	vector<ll> one, two;
	ll sum = 0;
	
	FOR(i,1,n) {
	  ll w, c;
	  get(w); get(c);
	  if( w == 1 )
	  	one.pb(c);
	  else
	  	two.pb(c);
	  sum += w;
	}
	
	sort( all(one), greater<ll>() );
	sort( all(two), greater<ll>() );
	
	
	FOR(i,1,sum) {
		ll c = 0;
		dp[i] = dp[i-1];
		
		if( x[i-1] < one.size() && dp[i-1] + one[x[i-1]] > dp[i] )
		 { dp[i] = dp[i-1] + one[x[i-1]]; c = 1; }
		if( i-2 >= 0 && y[i-2] < two.size() && dp[i-2] + two[y[i-2]] > dp[i] )
		 { dp[i] = dp[i-2] + two[y[i-2]]; c = 2; }
				
		if( c == 1 ) { x[i] = x[i-1] + 1; y[i] = y[i-1]; }
		else if( c == 2 ) { y[i] = y[i-2] + 1; x[i] = x[i-2]; }
		else {  x[i] = x[i-1];	y[i] = y[i-1]; }

		
		printf("%lld ", dp[i]);
	}
	 
}


