#include <bits/stdc++.h>
#define ll int
#define get(a) scanf("%d", &a)
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSTL(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( int i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

ll w[505][505] = {0};
ll rank[505][505] = {0};
ll m[505][505] = {0};


int main() {
//	INPFILE;
	ll t; get(t);
	while(t--) {
		ll n; get(n);
		ll cM[505] = {0}, cW[505] = {0}, next[505] = {0};
		bool taken[505] = {0};
		
		memset( w, 0, sizeof w );
		memset( m, 0, sizeof w );
		memset( rank, 0, sizeof w );
		
		FOR(i,1,n)
		 FOR(j,0,n) {
		  get(w[i][j]);
		  if( j > 0 )
		  	rank[i][ w[i][j] ] = n-j+1;
		  }
	   
		FOR(i,1,n)
		 FOR(j,0,n)
		  get(m[i][j]);
		  
		FOR(i,1,n)
		 next[i] = 1;
		
				
		queue<ll> q;
		
		FOR(i,1,n)
		 q.push(i);
		
		while( !q.empty() ) {
			ll man = q.front();
			q.pop();
			
		//	cout << " MAN: " << man;
			
			for( ; next[man] <= n; next[man]++ ) {
				ll i = next[man];
				ll woman = m[man][i];
			 if( !taken[ woman ] ) { 
			   taken[woman] = 1; 
			   cM[man] = woman; 
			   cW[woman] = man;
			   
			   break;
			 }
			 else if( rank[woman][man] > rank[woman][ cW[woman] ] ) {
			 	q.push(cW[woman]);
			 	cM[man] = woman;
			 	cW[woman] = man;
			 	
			 	break;
			 }

			}
			
		//	cout << " WOMAN: " << cM[man] << endl;
			
		}
		  
	   	FOR(i,1,n)
		 printf("%d %d\n", i, cM[i] );
		 
	}
}
