#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define llu long long
#define get(a) scanf("%lld", &a);
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
	ll t; get(t);
	while(t--) {
		ll n, s;
		get(n); get(s);
		
		ll min = n%100;
		ll hrs = n/100;
		
		ll ph, pm;
		ph = hrs; pm = min;
		
		ll mp = ( s/60 ) + ( s%60 != 0 );
		
		min += mp;
		hrs += min/60;
		hrs %= 24;
		min %= 60;
		
		if( hrs == 0 && min == 0 && s != 0 && s%60 != 0 )
		  { hrs = 23; min = 59; }
		
		char h[2], m[2];
		m[0] = ( min%10 ) +'0';
		m[1] = ( min/10 ) + '0';
		
		h[0] = ( hrs%10 ) + '0';
		h[1] = ( hrs/10 ) + '0';
		
		printf("%c%c%c%c\n", h[1],h[0],m[1],m[0] );
		
	}
}
