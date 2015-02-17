#include <bits/stdc++.h>
#include <cstdio>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( multiset<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

int main() {
	ll t; get(t);
	while(t--) {
		char str[100005];
		scanf("%s", &str);
		string a(str);
		a = " " + a;
		
		ll dp[100005] = {0};
		int prev[150] = {0};
		ll unsigned ans[100005] = {0};
		
		memset( prev, -1, sizeof prev );
			
		ans[0] = 1; dp[0] = 0;
		
		FOR(i,1,a.size()-1) {
			dp[i] = ans[i-1];
			 if( prev[a[i]] >= 1 )
			 	dp[i] -= ans[ prev[a[i]] - 1  ];
			if( dp[i] < 0 )
				dp[i] += MOD;
				
			ans[i] = ( ans[i-1] + dp[i] )%MOD;
			prev[ a[i] ] = i;
			//cout << " ANS: " << ans[i];
			//cout << "  DP: " << i << " " <<  dp[i] << endl;
		}
		
		
		
		printf("%ld\n", ans[a.size()-1]);
		  
	}
}
