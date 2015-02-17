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

ll v[2000+5], n;

ll search( ll x, ll y, ll val ) {
	ll mid = ( x + y )/2;
	
	while( x <= y ) {
		if( v[x] > val ) return x;
		if( v[y] <= val ) return y+1;
		
		if( v[mid] > val ) y = mid - 1;
		else if( v[mid] < val ) x = mid + 1;
		else if( v[mid] == val ) {
			int i;
			for( int i = mid+1; i < n; i++ )
				if( v[i] != val )
					return i;
			return i;
		}
	}
	
	return n;
}

int main() {
	while(1) {
        get(n);
		long ans = 0;
		
		if( n == 0 ) break;
		
		rep(n)
		 { get(v[i]); }
		
		sort(v,v+n);
		
		FOR(i,0,n-2)
		 FOR(j,i+1,n-1)
		  ans += max( 0, n - search( j+1,n-1, v[i]+v[j] ) );
		  
		printf("%ld\n", ans);
	}
}
