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
		ll w1, w2, n1, n2;
		get(w1); get(w2); get(n1); get(n2);
		ll sum = w1+w2;
		ll x, y; 		

			y = min( w1/2, n2 );
			n2 -= y;
			w1 -= y*2;
			x = min( w1, n1 );
			n1 -= x;
			w1 -= x;
			
			y = min( w2/2, n2 );
			n2 -= y;
			w2 -= y*2;
			x = min( w2, n1 );
			n1 -= x;
			w2 -= x;
		
		printf("%ld\n", sum-max(0L,w1)-max(0L,w2) );
		
		
		
	}
}

