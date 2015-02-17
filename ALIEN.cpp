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


pair<ll,ll> cmp( pair<ll,ll> a, pair<ll,ll> b ) {
	if( a.S == b.S ) {
	  if( a.F >= b.F )
	  	return b;
	  else
	  	return a;
	}
	else if( a.S > b.S )
		return a;
	else
		return b;	
}
	
int main() {
//	INPFILE;
	ll t; get(t);
	while(t--) {
		ll n, m;
		get(n); get(m);
		
		pair<ll,ll> ans = mp(0,0);
		ll sum = 0, count = 0, ptr = 0;
		vector<ll> v;
	
		rep(n) { 
		   ll x; get(x);
	   	   v.pb(x);
	   	   
		   sum += x;
		   count++;
		   
		   while( sum > m && count > 0 )
		   	{ sum -= v[ptr++]; count--; } 
		   
		   if( sum <= m )
		   	ans = cmp( ans, mp( sum, count ) );
		     
	    }   
	    	
		printf("%ld %ld\n", ans.F, ans.S);
	    
	}
}
