#include <bits/stdc++.h>
#include <cstdio>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector< pair<ll,ll> >::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set< pair< ll, pair<ll,ll> > >::iterator it = s.begin(); it != s.end(); it++ )
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
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

int main() {
	ll t;
	get(t);
	
	while(t--) {
		ll n, f, minx = LONG_MAX, ans = 0;
		get(n); get(f);
		vector<ll> v;
		map<ll,ll> s;
		
		rep(n)
		 { ll x; get(x); v.pb(x); s[x]++; minx = min(minx,x); }
		
		for( map<ll,ll>::reverse_iterator it = s.rbegin(); it != s.rend(); it++ ) {
			 ll val = it->first;
			//cout << " J: " << it->first << endl;
			ll ifind = it->second;
			
			ans+= ( ifind*(ifind-1) )/2;
		
			while(val%f == 0) {
				val /= f;
				if( val < minx ) break;
				
				ll find = s[val];
				ans += ifind*find;			
			}
		}
				
			
		
		printf("%ld\n", ans);
		 
		
	}
}
