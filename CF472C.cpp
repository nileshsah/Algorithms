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
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

int main() {
//	INPFILE;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll n; cin >> n;
	vector< pair<string,string> > v;
	
	FOR(i,1,n) {
		string f, s;
		cin >> f >> s;
		v.pb( mp(f,s) );
	}
	
	vector<ll> idx;
	
	FOR(i,1,n)
	 { ll x; cin >> x; idx.pb(x-1); }
	
	string last;
	
	last =  min( v[idx[0]].F, v[idx[0]].S );
	
	FOR(i,1,n-1) {
		ll ptr = idx[i];
		bool f = last < v[ptr].F;
		bool s = last < v[ptr].S;
		
		if(  f && s )
		  last = min( v[ptr].F, v[ptr].S );
		else if( f )
		  last = v[ptr].F;
		else if( s )
		  last = v[ptr].S;
		else
		 { cout << "NO"; return 0; }
	}
	
	cout << "YES";
}
