#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a)
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
	ll t;
	get(t);
	
	while(t--) {
	   ll a, b, c;
	   get(a); get(b); get(c);
	   ll ans = a*a - 2*b;
	   printf("%lld\n", abs(ans) );	   
	}
	
}
