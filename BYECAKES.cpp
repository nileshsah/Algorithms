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
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
using namespace std;

int main() {
  while(1) {
  	vector<ll> v, cake;
  	
  	rep(4) {
  		ll x; get(x);
  		v.pb(x);
  	}
  	
  	rep(4) {
  	  ll x; get(x);
  	  cake.pb(x);
  	}
  	
  	if( cake[0] == -1 && v[0] == -1 )
  		break;
  		
  	ll num = 0;
  	
  	rep(4) {
      num = max( num, ceil( double(v[i])/cake[i] ) );
	}
  	
  	rep(4) {
  	  printf("%ld ", num*cake[i] - v[i]);	
	}
	printf("\n");
  	
  }
}
