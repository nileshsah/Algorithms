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
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

ll modpow(ll base,ll exp, ll MOD){
	ll ans=1;
	while(exp){
		if(exp%2) ans=ans*base%MOD;
		base=base*base%MOD;
		exp/=2;
	}
	if(ans<0) ans+=MOD;
	return ans;
}

int main() {
	ll t; get(t);
	while(t--) {
		ll m, s;
		get(m); get(s);

		ll arr[10][25] = {0};
		
		FOR(i,0,s-1) {
		  ll p = modpow(10,i,m);
		 FOR(j,0,9)
		  arr[j][i] = ( j*p )%m;
		}
		
		ll dp[25][1005] = {0};
		ll num = ( s%2 == 0 ) ? (s-1)/2 : (s-1)/2 - 1;
		
		if( num >= 0 )
		 FOR(i,1,9)
		  dp[0][(arr[i][0]+arr[i][s-1])%m]++;
		
		FOR(i,1,num)
		 FOR(k,0,9)
		  FOR(j,0,m-1)
		   dp[i][(j+arr[k][i]+arr[k][s-i-1])%m] += dp[i-1][j];
		
		ll ans = 0;
		
		if( s == 1 ) {
			ans = 10/m - ( 10%m == 0 );
		}
		else if( s%2 != 0 ) {
		 FOR(k,0,9)
		  ans += dp[num][(m-arr[k][num+1]+m)%m];
		}
		else {
			ans = dp[num][0];
		}
			
	/*	FOR(i,0,num) {
		 FOR(j,0,m-1)
		  cout << dp[i][j] << " ";
		 cout << endl;
		}
	*/	
		printf("%lld\n", ans);
			
		
	}
}
