#include <bits/stdc++.h>
#define ll int
#define get(a) scanf("%d", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
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
//	INPFILE;
	ll t; get(t);
	while(t--) {
		ll n; get(n);
		ll sum = 0;
		ll zc = 0;
		
		bool flag = 0;
		
		rep(n) { 
		 ll x; get(x); 
		 if( x > 100 )
		  flag = 1;
		 if( x == 0 )
		  zc++;
		 sum += x;
	    }
	    
	    if( flag )
	      { printf("NO\n"); continue; }
		
		if( sum - 100 >= n-zc || sum - 100 < 0 )
		 printf("NO\n");
		else
		 printf("YES\n");
		 
	}
}
