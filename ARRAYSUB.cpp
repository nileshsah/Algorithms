#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) a >= 0 ? a : -a
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
using namespace std;

int main() {
	ll n, k;
	get(n);
	
	vector<ll> v(n+1,0);
	
	rep(n)
	 get( v[i] );
	get(k);
	 
	 ll me = -1, up;
	 
	 FOR(i,0,k)
	   if( v[i] >= me )
	    { me = v[i]; up = i; }
	 printf("%ld ", me);
	 
	 FOR( i, k, n ) {
			if( v[i] >= me )
			 { up = i; me = v[i]; }
			
			if( i - up >= k ) {
				me = -1;
				FOR(j, up+1, i+1 )
				 if( v[j] >= me )
				  { me = v[j]; up = j; }
			}
			
			printf("%ld ", me);
				 
	 }
	
}
