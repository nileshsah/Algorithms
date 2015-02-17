#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%d", &a)
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSTL(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( int i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

ll num[3]= {0};

int main() {
	string s;
	cin >> s;
	vector< pair<ll,ll> > v;
	v.pb( mp(0,0) );
	
	FOR(i,0,s.size()-1) {
	 num[s[i]-'A']++;
     v.pb( mp( num[0] - num[1], num[0] - num[2] ) );
	}
	
	sort( all(v) );
		 
	ll ans = 0;
	pair<ll,ll> p = mp(LONG_MAX,LONG_MAX);
	ll add = 1;
	
	FOR(i,0,v.size()-1)
	 if( p == v[i] )
	 	{ ans += add; add++; }
	else
		{ p = v[i]; add = 1; }
	
	cout << ans;
		
		
}
