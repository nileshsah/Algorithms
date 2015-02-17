#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a);
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

vector<ll> v[505];	
ll mark[505] = {0};
bool flag = 0;

bool explore[505] = {0};

void dfs( ll r, ll x ) {
		
	if( flag )
		return;
	explore[r] = 1;
	mark[r] = x;
	
	ll xx;
	
	if( x == 1 )
		xx = 2;
	else
		xx = 1;
			
	repVector(v[r]) {
	 if( mark[*it] == mark[r] )
	 	{ flag = 1; return; }
	 else
	   mark[*it] = xx;
	}
	
	repVector(v[r])
	 if( !explore[*it] )
	  dfs( *it, xx );
}

int main() {
//	INPFILE;
	ll t, c= 1; get(t);
	while(t--) {
		ll n; get(n);
		
		
		FOR(i,1,n) {
			v[i].clear();
			ll m; get(m);
		    FOR(j,1,m)
		 	 { ll x; get(x); v[i].pb(x); }
		 }
		 
		if( n == 1 )
		 { printf("Case %ld: 1 0 1\n", c++ ); continue; }

		 
		 flag = 0;
		 memset( explore, 0, sizeof explore );
		 memset( mark, 0, sizeof mark );
		 
		 
		 FOR(i,1,n)
		  if( !explore[i] )
		  	dfs( i, 1 );
		  	
		 if( flag )
		 	  { printf("Case %ld: 0 0 0\n", c++ ); continue; }
		
		ll a = 0, b = 0;
		
		FOR(i,1,n)
		 if( mark[i] == 1 ) a++;
		 else if( mark[i] == 2 ) b++;
		
		printf("Case %ld: 1 %ld %ld\n", c++, min(a,b), max(a,b) );
	}
}
