#include <bits/stdc++.h>
#include <cstdio>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector< pair<ll,ll> >::iterator it = v.begin(); it != v.end(); it++ )
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

vector<ll> prime;

void sieve() {
	ll n = 33811;
	bool a[100000] = {0};	
	
	FOR(i,2,n+1)
	 if( a[i] == 0 ) {
	 	prime.pb(i);
	 	if( prime.size() > 3000 ) return;
	 	ll cc = 0;
	 	for( ll j = i+1; j <= n; j++ ) {
	 	  if( a[j] == 1 ) continue;
	 	  else cc++;
	 	  
	 	  if( cc == i ) { a[j] = 1; cc = 0; }
		}
	 	  
	 }
}

int main() {
	sieve();
	while(1) {
		ll n; get(n);
		if( n == 0 ) return 0;
		printf("%ld\n",prime[n-1]);
	}
}
