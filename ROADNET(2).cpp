#include <bits/stdc++.h>
#include <cstdio>
#define ll int
#define get(a) scanf("%d", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector< pair< ll, pair<ll,ll> > >::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set< pair< ll, pair<ll,ll> > >::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

int main()  {
	ll t; get(t);
	
	while(t--) {
	  ll a[205][205] = {0}, n;
	  get(n);
	  
		FOR(i,0,n)
		 FOR(j,0,n)
		   get(a[i][j]);
		
		FOR(i,0,n)
		 FOR(j,i+1,n) {
		  bool flag = 1;
		  FOR(k,0,n)
		   if( k == i || k == j ) continue;
		   else if( a[i][k] + a[k][j] == a[i][j] ) { flag = 0; break; }
		  
		  if( flag )
		  	printf("%d %d\n", i+1, j+1 );
		}
		
	}
}
