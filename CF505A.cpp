#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
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

bool isPalin( string s ) {
	ll len = s.size();
	
	FOR(i,0,len/2)
		if( s[i] != s[ len - 1 - i ] )
			return 0;
	return 1;
}

int main() {
	string s, temp;
	cin >> temp;
	
	FOR(i,'a','z') {
		s = temp;
		FOR(j,0,s.size()) {
		 s.insert( j, 1, char(i) );
		 if( isPalin(s) )
		   { cout << s; return 0; }
		 s = temp;
		}
	}
	
	cout << "NA";
	
}
