#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define get(a) scanf("%lld", &a)
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for(vector< pair<ll,ll> >::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set< pair< ll, pair<ll,ll> > >::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 10000007
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

ll gcd( ll a, ll b ) { return ( b == 0 ? a : gcd( b, a%b ) ); }

inline ll lcm( ll a, ll b ) { return ( a * b )/gcd(a,b); }

int main() {
	while(1) {
		ll n, m;
		get(n); get(m);
		
		if( n == 0 && m == 0 ) return 0;
		ll val =  lcm(n,m);
		printf("%lld\n", (val/n) * (val/m)  );
	}
}
