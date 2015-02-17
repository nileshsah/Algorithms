#include <bits/stdc++.h>
#include <cstdio>
#define ll long
#define get(a) scanf("%ld", &a)
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
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

int getnum( string a ) {
		ll num = 0;
		
		FOR(i,1,a.size()) {
			if( isdigit(a[i]) )
				continue;
			ll dig = 1;
			if( isdigit(a[i-1]) ) dig = a[i-1] - '0';
			
			ll mul = 0;
			switch(a[i]) {
				case 'm': mul = 1000; break;
				case 'c': mul = 100; break;
				case 'x': mul = 10; break;
				case 'i': mul = 1; break;
			}
			
			num += dig*mul;
		}
		
		return num;
}

int main() {
	ll t;
	get(t);
	
	while(t--) {
		string a, b;
		cin >> a >> b;
		
		a = "z" + a;
		b = "z" + b;
		
		ll x = getnum(a);
		ll y = getnum(b);
		
		ll ans = x + y;
		stack<char> s;
		char mcxi[] = { 'i', 'x', 'c', 'm' };
		ll k = 0;
		
		while( ans != 0 ) {
			if( ans%10 != 0 )
				s.push(mcxi[k]);
			if( ans%10 != 0 && ans%10 != 1 )
				s.push( ans%10 + '0' );
			k++;
			ans /= 10;
		}
		
		while( !s.empty() )
		{ printf("%c", s.top() ); s.pop(); }
		printf("\n");
		
	}
}
