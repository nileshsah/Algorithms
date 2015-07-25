#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
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
		ll x, y, k, n;
		get(x); get(y); get(k); get(n);
		bool flag = 0;
		
		FOR(i,1,n) {
			ll p, c;
			get(p); get(c);
			
			if( p >= x-y && c <= k )
			  { flag = 1; }
		}
		
		if(flag)
		 printf("LuckyChef\n");
		else
		 printf("UnluckyChef\n");
	}
}
