#include <bits/stdc++.h>
#include <cstdio>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector< pair<ll,ll> >::iterator it = v.begin(); it != v.end(); it++ )
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

vector<ll> luck;

void sieve( ll n ) {
	ll flag[4000] = {0};
	
	FOR(i,2,n) {
		if( flag[i] == 0 ) {
		  for( ll j = i; j <= n; j += i )
				flag[j]++;
		}
		else if( flag[i] >= 3 )
			luck.pb(i);
	}
}

int main() {
	sieve(4000);
	sort( all(luck) );
	
	ll t; get(t);
	while(t--) {
		ll x; get(x);
		printf("%ld\n", luck[x-1]);
	}
	return 0;
}
