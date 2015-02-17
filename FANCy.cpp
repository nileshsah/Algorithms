#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a);
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

int main() {
	ll t; get(t);
	while(t--) {
		char str[50];
		scanf("%s", &str);
		
		ll dp[50] = {0};
		dp[strlen(str)-1] = dp[strlen(str)] = 1;
		
		for( ll i = strlen(str)-2; i >= 0; i-- ) {
			ll j = i+1;	
			dp[i] = dp[j];
				
			while( j < strlen(str) && str[j] == str[i] )
			 {   dp[i] += dp[j+1]; j++;   }
	//	  cout << " REC: " << i << " " << dp[i] << endl;
		}
		
		printf("%ld\n", dp[0]);
		 
	}
}
