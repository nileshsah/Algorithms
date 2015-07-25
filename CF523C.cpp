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

ll front[1000005] = {0};
ll back[1000005] = {0};

int main() {
//	INPFILE;
	string s, t;
	cin >> s >> t;
	ll ptr = 0;
	
	FOR(i,0,t.size()-1) {
	   front[i] = front[max(0LL,i-1)];
	   if( s[ptr] == t[i] )
	    ptr++;
	   if( ptr == s.size() )
	   	{ front[i]++; ptr = 0; }
	}
	
	ptr = s.size()-1;
	ROF(i,t.size()-1,0) {
		back[i] = back[i+1];
		if( s[ptr] == t[i] )
		  ptr--;
		if( ptr == -1 )
		 { ptr += s.size(); back[i]++; }
	}
	
	ll ans = 0;

	
	FOR(i,0,t.size()-1) {
	   if( front[i] > 0 && back[i+1] > 0 )
	   	ans++;
	}
	
	cout << ans;

}
