#include <bits/stdc++.h>
#include <cstdio>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
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
	ll n; get(n);
	while(n--) {
		ll x; get(x);
		
		if( x%2 != 0 )
		  { printf("%ld\n", x); continue; }
		  
		ll temp = x;
		ll num = 0;
		
		while( temp >>= 1 )
			num++;
		ll ptr = pow(2,num);
		ll y = 0, idx = 0;
		
		while( ptr >= 1 ) {
			if( (ptr&x) )
				y += pow(2,idx);
			idx++;
			ptr /= 2;
		}
		
		
		printf("%ld\n", y);
		
		
	}
}
