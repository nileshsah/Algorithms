#include <bits/stdc++.h>
#include <cstdio>
#define ll long
#define get(a) scanf("%ld", &a);
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

int main() {
	ll t; get(t);
	while(t--) {
		ll n, m;
		get(n); get(m);
		queue< pair<ll,ll> > q;
		vector<ll> p;
		
		rep(n) { ll x; get(x); q.push( mp(i,x) ); p.pb(x); }
		sort( all(p), greater<ll>() );
		
		ll min = 0;
		
		while( !q.empty() ) {
			pair<ll,ll> x = q.front();
			q.pop();
			if( x.S == *p.begin() ) {
				min++;
				p.erase(p.begin());
				if( x.F == m )
					break;
			}
			else
			  q.push(x);			
		}
		
		printf("%ld\n", min);
		
		
	}
}
