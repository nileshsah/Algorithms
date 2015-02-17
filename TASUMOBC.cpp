#include <bits/stdc++.h>
#define ll long long unsigned
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

ll fact( ll x ) {
	if( x <= 1 )
		return 1;
	return x*fact(x-1);
}

ll nCr( ll n, ll r ) {
	return fact(n)/( fact(r)*fact(n-r) );
}

int main() {
//	cout << fact(5);
	
	FOR(i,1,17) {
		ll ans = 0; ll sum[5] = {0};
		cout << " FOR: " << i << " - > ";
	 FOR(j,0,i) {
	 	ans += nCr(i,j)%3; 
	 	sum[nCr(i,j)%3]++;
		 cout << nCr(i,j)%3 << " "; 
	 }
	// cout << endl;
	 cout << " = " << ans << endl;
	 //cout << sum[0] << " " << sum[1] << " " << sum[2] << endl;
	}
	  
	
}
