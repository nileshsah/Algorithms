#include <bits/stdc++.h>
#define ll long long
#define get(a) cin >> a;
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<string>::iterator it = s.begin(); it != s.end(); it++ )
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

set<string> s;
set<string> org;
map< string, string > m;

string getname( string a ) {
	if( m.find(a) == m.end() )
		return a;
	else
		return getname( m[a] );
}

int main() {
//	INPFILE;
	ll q; cin >> q;
	FOR(i,1,q) {
		string a, b;
		cin >> a >> b;
		if( s.count(a) == 0 )
		  { org.insert(a); }
		s.insert(b);
		m[a] = b;	
	}
	
	cout << org.size() << endl;
	repSet(org) {
		cout << *it << " " << getname(*it) << endl;
	}
}
