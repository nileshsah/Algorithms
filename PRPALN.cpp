#include <bits/stdc++.h>
#include <cstdio>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 1; i <= n; i++ )
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
#define MOD 10000007
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
		char str[100000+5];
		scanf("%s", &str);
		string a(str),b;
		
		for( ll i = a.size()-1; i >= 0; i-- )
			b.pb(a[i]);
		
		bool flag = 1;
		
		FOR(i,0,a.size()) {
			if( a[i] == b[i] )
				continue;
		
			string x = a.substr(i+1);
			ll pos = a.size()-1-i;
			string y = b.substr(i,pos-i);
			y = y + b.substr(pos+1);
			
			if( x == y ) break;
			
			 x = b.substr(i+1);
			 pos = b.size()-1-i;
			 y = a.substr(i,pos-i);
			 y = y + a.substr(pos+1);
			
			if( x == y ) break;
			else { flag = 0; break; }
		}
		
		if( flag )
			printf("YES\n");
		else
			printf("NO\n");
		  
		
	}
}
