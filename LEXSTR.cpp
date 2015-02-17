#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define get(a) cin >> a
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set< pair< ll, pair<ll,ll> > >::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

vector<ll> v[100005];
string s;
bool mark[100005] = {0};

void dfs( vector<ll>& adj, vector<ll>& pos, ll r ) {
	mark[r] = 1;
	adj.pb(s[r]); pos.pb(r);
	
	repVector(v[r])
	  if( !mark[*it] )
	  	dfs( adj, pos, *it );
}

int main() {
//	freopen( "input.in", "r", stdin );
	ll t; get(t);
	while(t--) {
		char str[100005];
		scanf("%s", &str);
		
		s = string(str);
		
		rep(s.size())
		  v[i].clear();
		memset( mark, 0, sizeof mark );
		
		ll m; get(m);
		rep(m) {
		   ll x, y;
		   get(x); get(y);
		   v[x].pb(y); v[y].pb(x);			
		}
		
		matrix G, P;
		ll count = 0;
		
		char ans[100005] = {0};
		
		FOR(i,0,s.size()-1)
		 if( !mark[i] ){
		 	vector<ll> adj, pos;
		 	dfs( adj, pos, i );
		 	
		 	sort( all(adj) );
		 	sort( all(pos) );

		 	ll c = 0;
		 	repVector(adj)
		 	  ans[ pos[c++] ] = char(*it);
		 }
		 
		 ans[s.size()] = '\0';
		 printf("%s\n", ans);
	
	}
}
