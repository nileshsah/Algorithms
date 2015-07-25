#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( auto it = s.begin(); it != s.end(); it++ )
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
	ll t; cin >> t;
	while(t--) {
		bool num[1000005] = {0}, mnum[1000005] = {0};
		ll n; cin >> n;
		set<ll> v, w;
		FOR(i,1,n)
		 { ll x; cin >> x; v.insert(x); num[x] = 1; mnum[x] = 1; }
		
		ll minx = 0;
		
		repSet(v) {
		  ll ptr = *it;
		  if( !num[ptr] ) continue;
		  
		  if( num[ptr+1] ) {
		  	num[ptr+1] = num[ptr] = num[ptr+2] = 0;
		  }
		  else {
		  	num[ptr] = num[ptr-1] = num[ptr+1] = 0;
		  }
		  minx++;
		}
		
		ll maxx = 0;
		
		repSet(v) {
			ll ptr = *it;
			if( !mnum[ptr] ) continue;
			mnum[ptr+1] = mnum[ptr] = 0;
			maxx++;
		}
		
		cout << minx << " " << maxx << "\n";
				
	}
}
