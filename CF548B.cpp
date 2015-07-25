#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define MOD 1000000007
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

int main() {
//	INPFILE;
	ll n, m, q;
	cin >> n >> m >> q;
	bool arr[505][505] = {0};
	
	FOR(i,1,n)
	 FOR(j,1,m)
	  cin >> arr[i][j];
	
	ll ans[505] = {0};
	ll cc = 0;
	

	
   FOR(i,1,n) {
   	 ll y = 1;
    FOR(j,1,m) { 
     if( arr[i][j]*arr[i][j-1] )
       { y++; ans[i] = max( ans[i], y ); }
     else 
       y = 1;
     if( arr[i][j] )
      cc++;
  	}
   }
   
   multiset<ll> s;
   FOR(i,1,n)
     { s.insert(ans[i]); }
    
    
    while(q--) {
    	ll x, y;
    	cin >> x >> y;
    	
    	s.erase(s.find(ans[x]));
    
		if( arr[x][y] )
    	 cc--;
    	else
    	 cc++;
    	 
    	arr[x][y] = !arr[x][y];
    	ans[x] = 0;
    	ll num = 1;
    	
    	FOR(j,1,m) {
		  if( arr[x][j]*arr[x][j-1] )
		    { num++; ans[x] = max( ans[x], num ); }
		   else 
		     num = 1;
		 }
	    	
    	s.insert(ans[x]);
    	
		cout << max(*s.rbegin(), ( cc > 0 )*1LL ) << "\n";
	}
}
