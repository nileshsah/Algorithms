#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main() {
	ll t; get(t);
	while(t--) {
		ll n, k;
		get(n); get(k);
		ll left = k+1, count = 1;
		
		FOR(i,1,n) {
		  left--;
		  if( left <= 0 )
		  	{ left = k; count++; }
		  ll x; get(x);
		  
		  if( x > left ) {
		  	ll q = x - left;
		  	count += ceil(1.0*q/k);
		  	left += ceil(1.0*q/k)*k - x;
		  }
		  else
		   left -= x;
		}
		printf("%lld\n", count);
	}
}
