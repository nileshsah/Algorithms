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

char mark[105][105];
ll n, m;

ll dfs( ll x, ll y ) {
	ll maxD = 0;
	ll maxL = 0;
	ll c = 0;
	
	FOR(i,x+1,n)
	 if( mark[i][y] == 'L' )
	 	c++;
	 else if( mark[i][y] == 'H' )
	 	break;
	 if( c > maxL )
	  { maxL = c; maxD = 3; }
	
	c = 0;
	FOR(i,y+1,m)
	 if( mark[x][i] == 'L' )
	 	c++;
	 else if( mark[x][i] == 'H' )
	 	break;
	if( c >= maxL )
	 { maxL = c; maxD = 2; }
	
	c = 0;
	for( ll i = x-1; i > 0; i-- )
	 if( mark[i][y] == 'L' )
	 	c++;
	 else
	 	break;
	 if( c > maxL )
	  { maxL = c; maxD = 1; }
	
	c = 0;
	for( ll i = y-1; i > 0; i-- )
	 if( mark[x][i] == 'L' )
	 	c++;
	 else if( mark[x][y] == 'H' )
	 	break;
	if( c >= maxL )
	 { maxL = c; maxD = 4; }	
	
	return maxD;	
}


int main() {
//	INPFILE;
	ll t; get(t);
	while(t--) {
		get(n); get(m);
		cin.ignore();
		
		ll lane = 0;
		
		FOR(i,1,n)
		 FOR(j,1,m) {
		  cin >> mark[i][j];
		  if( mark[i][j] == 'L' )
		  	lane++;
		 }
	    
	    ll ans = 0;
	    
	    FOR(i,1,n)
	     FOR(j,1,m)
	       if( mark[i][j] == 'L' ) {
	       	   ans++;
	       	   ll D = dfs(i,j);
	       	   
	       	   if( D == 1 )
	       	    for( ll k = i; k > 0; k-- )
	       	    	if( mark[k][j] == 'H' )
	       	    		break;
	       	    	else
	       	    		mark[k][j] = '0';
	       	   
	       	   if( D == 2 )
	       	    FOR(k,j,m)
	       	     if( mark[i][k] == 'H' )
	       	     	break;
	       	     else
	       	     	mark[i][k] = '0';
	       	   
	       	   if( D == 3 )
	       	    FOR(k,i,n)
	       	     if( mark[k][j] == 'H' )
	       	     	break;
	       	     else
	       	     	mark[k][j] = '0';
	       	   
	       	   if( D == 4 )
	       	    for( ll k = j; k > 0; k-- )
	       	     if( mark[i][k] == 'H' )
	       	     	break;
	       	     else
	       	     	mark[i][k] = '0';
	       	     	
	       	  
	       	/*  FOR(x,1,n) {
	       	  	FOR(y,1,m)
	       	  	 cout << mark[x][y] ;
	       	  	cout << endl;
	       		}
	       		cout << "\n\n\n";
	       	    */
		   }
		 
		
		cout << ans << endl;
	}
}
