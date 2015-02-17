#include <bits/stdc++.h>
#include <cstdio>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<int>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) a >= 0 ? a : -a
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define L 2*r
#define R 2*r+1
using namespace std;

bool arr[1000+5] = {0};
vector<long> prime;

void sieve() {
	ll n = 1000+5;
	
	FOR(i,2,n) {
		if( arr[i] == 1 )
			continue;
		prime.pb(i);
		for( long long k = (long long int)i*i; k <= n; k+=i )
			arr[k] = 1;
	}
}

ll gcd(ll a, ll b) { return (b == 0 ? a : gcd(b, a % b)); }

int main() {
	ll t;
	get(t);
	
	sieve();
	while(t--) {
		ll a, b;
		get(a); get(b);
		ll gc = gcd(a,b);
		ll lim = gc;
		
		if( gc == 1 )
		 { printf("1\n"); continue; }
		
		ll i = 0;
		ll ans = 1;
		
		while( prime[i] <= gc && i < prime.size() ) {
		  ll p1 = 0;
		  while( gc%prime[i] == 0 )
		  	{ p1++; gc /= prime[i]; }
		  ans *= (p1 + 1);
		  i++;
		}
		
		if( gc > 1 )
		 ans *= 2;
	
		
		printf("%ld\n", ans);
		
		
	}
}
