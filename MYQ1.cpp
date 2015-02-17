#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
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
		ll x; get(x);
		if( x == 1 )
		 { printf("poor conductor\n"); continue; }
		
		printf("%lld ", (x-2)/5 + 1 );
		ll num = x%10;
		
		if( num == 1 || num == 2 || num == 6 || num == 7 )
			printf("W ");
		else if( num == 3 || num == 0 || num == 4 || num == 9 )
			printf("A ");
		else if( num == 5 || num == 8 )
			printf("M ");
		
		if( num == 2 || num == 1 || num == 3 || num == 0 )
			printf("L");
		else
			printf("R");
		
		printf("\n");
				
	}
}
