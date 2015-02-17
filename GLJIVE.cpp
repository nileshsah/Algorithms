#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <cstring>
#define ll int
#define get(a) scanf("%d", &a)
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
	ll n = 10;
	vector<ll> v;

	while(n--) {
		ll x; get(x);
		v.pb(x);
	}
	ll diff = INT_MAX, sum = 0;
	
	FOR(i,0,v.size()) {
		if( abs( 100 - ( sum + v[i] ) ) <= diff ){
			sum += v[i];
			diff = abs( 100 - ( sum  ) );
		}
		else
			break;
	}
	
	cout << sum;
}
