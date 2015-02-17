#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
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

int main() {
//	INPFILE;
	ll t; get(t);
	while(t--) {
	   ll n, m;
	   get(n); get(m);
	   vector<ll> v;
	   vector< pair<ll,ll> > adj;
	   ll mark[100005] = {0};
	   
	   FOR(i,1,n)
	    mark[i] = i;
	   
	   rep(n) 
	    { ll x; get(x); v.pb(x); }
	   
	   rep(m) {
	   	  ll x, y;
	   	  get(x); get(y);
	   	  adj.pb( mp( min(x,y), max(x,y) ) );
	   }
	   
	   sort( all(adj) );
	   
	   FOR(i,1,adj.size()-1)
	    if( adj[i].F <= adj[i-1].S ) {
	    	adj[i-1].S = max( adj[i-1].S, adj[i].S );
	    	adj[i] = adj[i-1];
		}
	   	
	   pair<ll,ll> last = mp(0,0);
	   ll idx = n+1;
	   
	   FOR(i,0,adj.size()-1)
	    if( last != adj[i] ) {
	    	last = adj[i];
	    	FOR(j,last.F,last.S)
	    	 mark[j] = idx;
	    	idx++;
		}
		
		bool flag = 1;
		
	   FOR(i,1,n)
	    if( mark[ v[i-1] ] != mark[i] )
	     { flag = 0; break; }
	   
	   if(flag)
	    printf("Possible\n");
	   else
	   	printf("Impossible\n");	      
	}
}
