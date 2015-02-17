#include <bits/stdc++.h>
#include <cstdio>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for(vector< pair<ll,ll> >::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set< pair< ll, pair<ll,ll> > >::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<double> >
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

ll v[1000000+5], z[1000000+5];
bool index[1000000+5] = {0};

int main() {
	ll n; get(n);

	ll mxx = 0;
	set<ll> s;
	
	ll que[300000] = {0};
	
	rep(n) { 
	 	ll x, y; 
		get(x); get(y);
		v[x] = y;
		z[y] = x;
		
		index[y] = 1;
		
		if( x == 0 )	que[2] = y;
		if( y == 0 )	que[n-1] = x;
		
		if( s.count(x) == 1 )
		   s.erase(x);
		else
		  s.insert(x);
		
		if( s.count(y) == 1 )
		  s.erase(y);
		else
		  s.insert(y);
	}
	
	if( index[*s.begin()] == 0 )
		{ que[1] = *s.begin(); que[n] = *s.rbegin(); }
	else { que[n] = *s.begin(); que[1] = *s.rbegin(); }
	
	for( int i = ( n%2 == 0 ) ? 2 : 1; i <= n-2; i += 2 )
		que[i+2] = v[que[i]];
	for( int j = n-1; j > 2; j -= 2 )
		que[j-2] = z[ que[j] ];
	
	FOR(i,1,n)
		printf("%ld ", que[i]);
	
	
	
	
	
}
