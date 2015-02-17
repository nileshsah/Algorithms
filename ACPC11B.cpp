#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <cstring>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define pb push_back
#define min(a,b) a < b ? a : b
#define absol(a) a >= 0 ? a : -a
using namespace std;

int binsearch( vector<ll> v, int start, int end, ll n ) {
	int mid = start + end;
	mid /= 2;
	
	if( v[mid] == n )
		{ return mid; }
		
	if( start >= end )
		return start;
		
	if( n > v[mid] )
		return binsearch( v, mid+1, end, n );
	else if( n < v[mid] )
		return binsearch( v, start, mid-1, n );
	
}

int main() {
	ll t;
	get(t);
	while(t--) {
		ll n, m;
		vector<ll> v1, v2;
		
		get(n);
		while(n--) {
		  ll x; get(x);
		  v1.pb(x);
		}
		
		get(m);
		while(m--){
		 ll x; get(x);
		 v2.pb(x);
		}
		
		sort( all(v2) );
		
		ll ans = LONG_MAX;
		
		repVector(v1) {
			int pos = 0;
			pos = binsearch( v2, 0, v2.size()-1, *it );		
			
			ans = min( ans, abs( *it-v2[pos] ) );			
			if( pos > 0 )
			 ans = min( ans, abs(*it-v2[pos-1]) );
			if( pos < v2.size()-1 )
			 ans = min( ans, abs(*it-v2[pos+1]) );
			 
		//	cout << " POS: " << pos << " for " << *it << " ans=" << ans << endl;
		}
		
		printf("%ld\n", ans);
		
			
	}
}
