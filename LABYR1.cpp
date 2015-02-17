#include <bits/stdc++.h>
#include <cstdio>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<int>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) a >= 0 ? a : -a
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define L 2*r
#define R 2*r+1
using namespace std;

bool explore[1000005];
vector<int> adj[1000+5];
ll maxcount = 0;
ll lbl[1005][1005];

ll dfs( ll a, ll val = 1 ) {
	vector<int> v;
	explore[a] = 1;
	ll m = val;
	
	if( adj[a].empty() )
		return 0;
	
	repVector( adj[a] ) 
	  if( !explore[*it] ) {
		ll ret = dfs( *it , val+1 ) ;
		m = max( ret, m );
		v.pb( ret - val );
	 }
	  
	ll ans = 0;
	sort( all(v), std::greater<int>() );
	
	if( v.empty() )
		ans = 1;
	else if( v.size() >= 2 )
	   ans = v[0]+v[1];
	else
	   ans = v[0];
	maxcount = max( maxcount, ans );
	
	return m;
}



int main() {
	ll t;
	get(t);
	
	while(t--) {
		ll c, r;
		memset( explore, 0, sizeof explore );
		memset( lbl, -1, sizeof lbl );
		
		char str[1005][1005] = {0};

		maxcount = 0;

		ll count = 1;
		get(c); get(r);
	//	cin.ignore();
		
		FOR(i,0,r-1)
			scanf("%s", str[i]);
		 
		 
		 FOR(i,0,r-1)
		  FOR(j,0,c-1) {
			if( str[i][j] == '.' ) {
				if( lbl[i][j] == -1 )
					lbl[i][j] = ++count;

		 	 if( str[i][j+1] == '.' ) {
		 	 	 if( lbl[i][j+1] == -1 )
		 	 		lbl[i][j+1] = ++count;
			  	adj[lbl[i][j]].pb(lbl[i][j+1]);
		 	  	adj[lbl[i][j+1]].pb(lbl[i][j]);
		 	 }
		 	 
		 	  if( str[i+1][j] == '.' ) {
		 	 	 if( lbl[i+1][j] == -1 )
		 	 		lbl[i+1][j] = ++count;
			  	adj[lbl[i+1][j]].pb(lbl[i][j]);
		 	  	adj[lbl[i][j]].pb(lbl[i+1][j]);
		 	 }
		 	 
		 	 
		 	}
		}
		
		FOR(i,1,count)
		  if( !explore[i] )
				dfs(i);
		
		printf("Maximum rope length is %ld.\n", maxcount );
		
		FOR(i,1,count)
		 adj[i].clear();
		
	}
	
}
