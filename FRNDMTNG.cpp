#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( auto it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
#define MOD 1000000000
#define foo pair< pair<ll,ll>, ll >
using namespace std;

int main() {
	ll t; get(t);
	while(t--) {
		ll T1, T2, t1, t2;
		get(T1); get(T2); get(t1); get(t2);
		swap(t1,t2);
	
		double ans = T1*T2;
		ll tx = t1, ty = t2, x = T1, y = T2;
		
		if( T1 > T2 ) {
		  swap(x,y);
		  swap(tx,ty);
		}
		
		  if( x-tx >= 0 )
			ans -= 0.5*(x-tx)*(x-tx);
		  if( y-ty >= 0 )
			ans -= 0.5*(y-ty)*(y-ty);
		  if( y-ty-x >= 0 )
			ans += 0.5*( y - ty - x )*( y - ty - x );
		  
		printf("%0.7lf\n",1.0*ans/(T1*T2));
		
	}
}
