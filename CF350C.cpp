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


inline string str( ll x, char d ) {
	if( d == 'x' ) {
		if( x < 0 )
		  return " L\n";
		else
		  return " R\n";
	}
	else if( d == 'y' ) {
		if( x < 0 )
		 return " D\n";
		else
		 return " U\n";
	}
}


int main() {
	std::ios::sync_with_stdio(false);
	ll n; cin >> n;
	vector< pair<ll,ll> > v;
	ll steps = 0;
	FOR(i,1,n) {
		ll x, y;
		cin >> x >> y;
		if(x) steps += 2;
		if(y) steps += 2;
		steps += 2;
		v.pb( mp(x,y) );
	}

	sort( all(v) );
	cout << steps << "\n";
	
	repVector(v) {
		if( it->F != 0 ) {
			stringstream ss;
		    string s;
			ss << abs(it->F); ss >> s;
			cout << ("1 " + s + str(it->F,'x'));
		}
		if( it->S != 0 ) {
			stringstream ss;
		    string s;
			ss << abs(it->S); ss >> s;
			cout << ("1 " + s + str(it->S,'y'));
		}
		cout << ("2\n");
		if( it->F != 0 ) {
			stringstream ss;
		    string s;
			ss << abs(it->F); ss >> s;
			cout << ("1 " + s + str(-it->F,'x'));
		}
		if( it->S != 0 ) {
			stringstream ss;
		    string s;
			ss << abs(it->S); ss >> s;
			cout << ("1 " + s + str(-it->S,'y'));
		}
		cout << ("3\n");	
	}
	
}
