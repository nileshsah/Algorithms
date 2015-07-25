#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
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
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

bool EQ( string a, string b, string c ) {
	if( a == b && b == c )
		return 1;
	return 0;
}

int main() {
	ll t; get(t);
	while(t--) {
		string f, b, bt, l, r, t;
		cin >> f >> b >> l >> r >> t >> bt;
		
		bool exp = EQ(f,bt,l) || EQ(f,l,t) || EQ(f,r,t) || EQ(f,r,bt);
		exp |= EQ(b,bt,l) || EQ(b,l,t) || EQ(b,r,t) || EQ(b,r,bt);
		
		if(exp)
		 cout << "YES\n";
		else
		 cout << "NO\n";
	}
}
