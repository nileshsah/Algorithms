#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
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

set<string> s;

void rec( string start, string end ) {
	if( end.empty() )
	 end = "";
	 
	FOR(i,'a','z') {
	 string p = start + char(i) + end;
	 s.insert(p);
	}
	
	if( end.empty() )
	 return;
	 
	start += end[0];
	end.erase(end.begin());
	return rec( start, end );
}

int main() {
	string s;
	cin >> s;
	rec( "", s );
	cout << ::s.size();
}
