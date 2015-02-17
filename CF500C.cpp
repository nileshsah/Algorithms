#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define max(a,b) ( (a > b) ? a : b )
#define min(a,b) ( (a < b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

int main() {
//	INPFILE;
	ll n, m;
	cin >> n >> m;
	
	ll w[n+1], v[m];
	rep(n)
	 cin >> w[i];
	
	ll ans = 0;
	
	rep(m) {
		cin >> v[i];
		
		set<ll> s;
		ll ptr = i-1;
		while( ptr >= 1 && v[ptr] != v[i] )
			{ s.insert( v[ptr] ); ptr--; }
		repSet(s)
		  ans += w[*it];
		 
	}


	cout << ans;		
		
}
