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


ll A[100005] = {0}, B[100005] = {0};

int main() {
//	INPFILE;
	ll n, x, y;
	get(n); get(x); get(y);
	
	vector<ll> v(n); 
	ll ans = 0;
	
	 rep(n) {
		ll q; get(q);
		A[i] = q;
		ans += q;
	 } 
	
	 rep(n) {
		ll q; get(q);
		B[i] = q;
		v[i] = B[i] - A[i];
	 }
	 
	 sort( all(v), greater<ll>() );
	
	ll a = n;
	ll b = 0;
	ll i = 0;
	 
	 while( i < n ) {
//	 	cout << ans << " " << a << " " << b << endl;
	 	if( v[i] < 0 && a <= x && b <= y && a+b == n )
	 		break;
	 	else
	 		{ ans += v[i]; a--; b++; i++; }
	 }
	
	cout << ans;
	 		

	 
	
	
}
