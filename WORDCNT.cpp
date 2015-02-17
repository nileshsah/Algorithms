#include <bits/stdc++.h>
#include <cstdio>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<int>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) a >= 0 ? a : -a
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define L 2*r
#define R 2*r+1
using namespace std;


int main() {
	ll t;
	get(t);
	cin.ignore();
		
	while(t--) {
		ll maxo = 0;
		char str[30000];
		cin.getline(str,30000);
		ll len = strlen(str);
		vector<ll> v;
		
		FOR(i,0,len) {
			ll c = 0;
			while( i < len && str[i] != ' ' )
			 { c++; i++; }
			if( c != 0 )
			 v.pb(c);
		}
		
		ll last = v[0];
		ll c = 0;
		FOR(i,0,v.size()) {
			while( last == v[i] )
			  { c++; i++; }
			maxo = max( maxo, c );
			last = v[i];
			c = 1;
		}
		
		printf("%ld\n", maxo);
	}

}
