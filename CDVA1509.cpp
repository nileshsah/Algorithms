#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define repSTL(i, c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

int main() {
	ll t; get(t);
	while(t--) {
		ll n; get(n);
		vector<ll> v1, v2, opt;
		
		for( ll i = 0; i < n/2; i++ )
		 { ll x; get(x); v1.pb(x); if( x-i > 0 ) opt.pb(x-i); }
		for( ll i = n/2, j =n/2-(n%2==0); i < n; i++, j-- )
		 { ll x; get(x); v2.pb(x); if( x-j > 0 ) opt.pb(x-j); }
		
		ll ans = INT_MAX;
		
		repVector(opt) {
			ll val = 0;
			for( ll i = 0; i < n/2; i++ )
			  if( v1[i] != *it+i )
			  	val++;
			for( ll k = 0, j = n/2 - (n%2==0); k < v2.size(); k++, j-- )
			  if( v2[k] != *it + j )
			    val++;
	//		cout << *it <<  " " << val << endl;
			ans = min( ans, val );
		}
		
		printf("%lld\n", ans);
		
	}
}
