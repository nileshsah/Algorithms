#include <bits/stdc++.h>
#include <cstdio>
#define ll int
#define get(a) scanf("%d", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector< pair<ll,ll> >::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set< pair< ll, pair<ll,ll> > >::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 10000007
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

inline int cnv( int i, int j )
 { return i*100+j; }

int main() {
  while(1) {
	ll n, m;
	char a[30][30];
	get(n); get(m);
	
	memset( a, 'X', sizeof a );
	if( n == 0 && m == 0 ) return 0;
	vector< pair<ll,ll> > v[3000];
	ll src, dest;
	cin.ignore();
	
	FOR(i,1,m) {
	 FOR(j,1,n) {
	 	a[i][j] = getchar();
	 	if( a[i][j] == 'S' )
	  	{ src = i*100+j; }
	    else if( a[i][j] == 'D' )
	  	{ dest = i*100+j; a[i][j] = '0'; }
	  }
	  cin.ignore();
	}	
	 	
	
	queue<int> q;
	q.push(src);
	
	FOR(i,1,m)
	 FOR(j,1,n)
	  if( isdigit(a[i][j] ) )
	   q.push( cnv(i,j) );
	
	
	
	while(!q.empty()) {
		ll ptr = q.front();
		q.pop();
		ll i = ptr/100, j = ptr%100;
	
		if( isdigit( a[i-1][j] ) )
		  v[ptr].pb( mp( cnv(i-1,j) , a[i-1][j] - '0' ) );
		if( isdigit( a[i+1][j] ) )
		 v[ptr].pb( mp( cnv(i+1,j) , a[i+1][j] - '0' ) );
		if( isdigit( a[i][j+1] ) )
		  v[ptr].pb( mp( cnv(i,j+1), a[i][j+1] - '0' ) );
		if( isdigit( a[i][j-1] ) )
		  v[ptr].pb( mp( cnv(i,j-1), a[i][j-1] - '0' ) );
	}
	
	 
	 vector<ll> D(3000,LONG_MAX);
	 set< pair<ll,ll> > s;
	 s.insert( mp(0,src) ); 
	 D[src] = 0;
	 
	 while(!s.empty()) {
	 	ll ptr = s.begin()->S;
	 	ll d = s.begin()->F;
	 	s.erase(s.begin());
	 	
		repVector(v[ptr]) 
		  if( D[it->F] > D[ptr] + it->S ){
		  	if( D[it->F] != LONG_MAX )
		  		s.erase( s.find( mp(D[it->F], it->F) ) );
		  	D[it->F] = D[ptr] + it->S;
		  	s.insert( mp( D[it->F], it->F ) );
		  	//cout << " SET: " <<  it->F << " " << D[it->F] << endl;
		}
	 }
	 
	 printf("%d\n", D[dest]);	
	
  }
}
	
