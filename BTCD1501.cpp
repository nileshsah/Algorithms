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
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

string foo( ll x ) {
	string s;
//	cout << " X: " << x << endl;
	while( x > 0 ) {
		s.pb( char(x%26) + 'a' - 1 );
		x /= 26;
	}
	
	reverse( all(s) );
	return s;
}

int main() {
//	cout << foo(703);
	
	ll t; get(t);
	while(t--) {
		string s;
		cin >> s;
		
		bool mark[500000] = {0};
		
		
		FOR(i,0,s.size()-1)
		 { mark[ s[i] - 'a' + 1 ] = 1; s[i] -= 'a'-1; }
		FOR(i,1,s.size()-1)
		 mark[ s[i-1]*26 + s[i] ] = 1;
		FOR(i,2,s.size()-1)
		 mark[ s[i-2]*676 + s[i-1]*26 + s[i] ] = 1;
		FOR(i,3,s.size()-1)
		 mark[ s[i-3]*17576 + s[i-2]*676 + s[i-1]*26 + s[i] ] = 1;
		
		FOR(i,1,475255)
		 if( !mark[i] )
		 	{ cout << foo(i) << endl; break; }
		 	
	}
}
