#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
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
#define INPFILE freopen("input.in","r",stdin)
using namespace std;


int main() {
	ll n, m;
	cin >> n >> m;
	ll sum = n+m;
	
	string s = "";
	bool last = 1; ll lc = 0;
	
	while( n+m > 0 ) {
		if( n >= m && last != 0 )
		 { s += "0"; n--; last = 0; lc = 0; }
		else if( m >= n && !( last == 1 && lc == 2 ) )
		 { s += "1"; m--; last = 1; lc = last*lc+1; }
		else if( last == 1 &&  n > 0 )
		 { s += "0"; n--; last = 0; lc = 0; }
		else
		 break;
	}
	
//	cout << s << endl;
	if( s.size() == sum )
	 cout << s;
	else
	 cout << "-1";
}
