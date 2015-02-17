#include <bits/stdc++.h>
#include <cstdio>
#define ll long long unsigned
#define get(a) scanf("%ulld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
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
#define mp make_pair
using namespace std;
 
ll gcd( ll a, ll b ) { return ( ( b == 0 ) ? a : gcd( b, a%b ) ); }
 
ll powmod( ll a, ll b , ll mod ) {
	if( a == 1 || b == 0 )
		return 1;
	if( b == 1 ) return a%mod;
	
	if( b%2 == 0 ) {
		ll num = powmod(a,b/2,mod);
		num = (num%mod)*(num%mod);
		return num%mod;
	}
	else {
		ll num = powmod(a,(b-1)/2,mod);
		num %= mod; num *= a%mod;
		return num%mod;
	}
	
}
 
int main() {
	ll t; get(t);
	while(t--) {
		ll n; get(n);
		if( n == 2 || n == 3 ) { printf("YES\n"); continue; }
		ll d = n-1, s = 0;
		
		while( d%2 == 0 )
		 { s++; d /= 2; }
		
		 int flag = 0;
		 
		 ll test = 3;
		 loop:
		 while(test--) {
		  ll rnd = 2 + rand()%(d-2);
		  ll x = powmod(rnd,d,n);
		  if( x == 1 || x == n-1 ) 
		  	{ flag++; continue; }
		  FOR(i,0,s-1) {
		  	x = powmod(x,2,n);
		  	if( x == 1 ) { flag--; }
		  	if( x == n-1 ) { flag++; goto loop; }
		  }
		  flag--;
		  cout << " RND: " << rnd << " F: " << flag << endl;
		 }
		
		bye: 
		 if(flag && n%2 != 0 ) printf("YES\n");
		 else printf("NO\n");
		 
	}
} 
