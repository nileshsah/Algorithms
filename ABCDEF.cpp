#include <iostream>
#include <vector>
#include <set>
#include <map>
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
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
using namespace std;

int main() {
	ll n, a[200] = {0};
	get(n);

	rep(n)
	 get(a[i]);
	
	ll add[10000+5], mul[10000+5];
	ll m = 0;
	
	vector<ll> lhs, rhs;
	
	FOR(i,0,n)
	 FOR(j,0,n){
		add[m] = ( a[i]+a[j] );
		mul[m] = ( a[i]*a[j] );	
		m++;
	 }
	
	FOR(i,0,n) 
	  FOR(j,0,m) {
	  	 rhs.pb( mul[j]+a[i] );	
		if( a[i] != 0 )
		  lhs.pb( add[j]*a[i] );
	 }
	
	sort( all(rhs) );
	sort( all(lhs) );
	ll sum = 0;
	
	FOR(i,0, lhs.size()){
		ll low = lower_bound( rhs.begin(), rhs.end(), lhs[i] ) - rhs.begin();
		ll high = upper_bound( rhs.begin(), rhs.end(), lhs[i] ) - rhs.begin();
		sum += high - low;
	}
	
	printf("%ld", sum);
}
