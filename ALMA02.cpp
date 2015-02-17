#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

int main() {
	ll t; get(t);
	while(t--) {
		ll n, k;
		get(k); get(n);
		
		ll val = 9; ll c = 1;
		
		while( n - val*c > 0 ) {
			n -= val*c;
			val *= 10; c++;
		}
		
		ll num = ceil(1.0*n/c) + pow(10,c-1)-1;
		
		ll x = c-n%c, y = 0;
		x %= c;
//		cout << " NUM: " << num << endl;
		
		while( num > 0 ) {
			ll q = num%10;
			num /= 10;
			if( y == x )
			  { printf("%lld\n", q); break; }
			y++;
		}
		
	}
}
