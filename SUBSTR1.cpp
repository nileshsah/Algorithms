#include <bits/stdc++.h>
#include <cstdio>
#define ll int
#define get(a) scanf("%d", &a)
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
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

int main() {
	ll t; 
	get(t);
	
	while(t--) {
		char str[50000+5];
		scanf("%s", &str);
		
		string a(str);
		
		
		vector<string> v;
		
		FOR(i,0,a.size())
			v.pb(a.substr(i));
		sort( all(v) );
		
		ll ans = v[0].size();
		
		FOR(i,1,v.size()) {
			ll k = 0, lcp = 0;
			while( k < min( v[i-1].size(), v[i].size() ) && v[i-1][k] == v[i][k] )
				{ lcp++; k++; }
			ans += v[i].size() - lcp;
		}
		
		printf("%d\n", ans);
		
	}
}
