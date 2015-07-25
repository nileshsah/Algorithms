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

ll dp[100005] = {0};
ll arr[100005] = {0};

ll n;

ll rec( ll x ) {
	if( x > n )
		return 0;
	if( dp[x] != -1 )
		return dp[x];
	return dp[x] = max( arr[x] + rec(x+2), rec(x+1) );
}
	
int main() {
	ll t; get(t);
	while(t--) {
		memset( dp, -1, sizeof dp );
		
		get(n);
		
		FOR(i,1,n)
		 get(arr[i]);
		
		cout << rec(1) << endl;
	}
}
