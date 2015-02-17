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

ll fact[10000005] = {0};

int main() {
	ll n, m;
	get(n); get(m);
	vector<ll> v;
	ll mx = 0;
	
	FOR(i,1,n)
	 { ll x; get(x); v.pb(x); mx = max(mx,x); }
	ll q = min(m,mx);
		
	fact[0] = 1;
	
	FOR(i,1,q+1) {
	 fact[i] = ( fact[i-1]*i )%m;
	 if( fact[i] == 0 ) break;
	}
	
	ll ans = 0;
	
	repVector(v) {
	   ll x = *it;
	   if( x+1 >= m )
	    { ans -= 1; ans += m; ans %= m; }
	   else
	    { ans += fact[x+1]-1; ans += m; ans %= m; }
	   
	   ll val; 
	   if( x%2 == 0 ) {
	    val = x/2; val %= m;
	    val *= (x%m); val %= m;
	    val *= (x+1)%m; val %= m;
	   }
	   else {
		 val = (x+1)/2; val %= m;
		 val *= (x%m); val %= m;
		 val *= (x%m); val %= m;
	   }
	   
	   ans += val; ans %= m; 
//	   cout << " X: " << x << " " << ans << endl; 
	}
	
	printf("%lld", ans);
	
}
