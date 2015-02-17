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

ll sum[] = {0,1,3,6,10,15,21,28,36,45};

ll solve( ll n ) {
	//1324
	ll ans = 0;
	ll ptr = 1;
	
	while( n > 0 ) {
		ll val = sum[n%10] + (n/10)*45;
		ll tmp = n/10;
		 while(tmp != 0 )
		 	{ val += ( tmp%10 )*(n%10+1); tmp /= 10; }
		
		val *= ptr;
		ptr *= 10;
		ans += val;
		n /= 10;
		n--;
	}
	
	return ans;
}

int main() {
    while(1) {
    	ll n, m;
    	get(n); get(m);
    	
    	if( n == -1 && m == -1 )
    		return 0;
    	
    	printf("%lld\n", solve(m)-solve(n-1));
    	
	}
}
