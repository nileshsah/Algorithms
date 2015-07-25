#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define MOD 1000000007
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

bool check( string s ) {
	FOR(i,0,s.size()/2)
	 if( s[i] != s[s.size()-1-i] )
	    return 0;
	return 1;
}

int main() {
	string s;
	cin >> s;
	ll k; cin >> k;
	ll len = s.size();
	
	if( len%k )
	 { cout << "NO"; return 0; }
	

	for( ll i = 0; i < len; i += len/k )
	  if( !check(s.substr(i,len/k)) )
	   { cout << "NO"; return 0; }
	
	cout << "YES";
}
