#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSTL(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
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

ll gcd( ll a, ll b ) { return ( b == 0 ? a : gcd(b,a%b) ); }

int main() {
	ll t; get(t);
	while(t--) {
		string a;
		cin >> a;
		
		ll val = 0, den = 1, mul = 1;
		rep(a.size())
		 if( a[i] != '.' )
		   { val *= 10; val += a[i] - '0'; den *= mul; }
		 else
		 	mul = 10;
		
		printf("%lld\n", den/gcd(val,den));	
	}
}
