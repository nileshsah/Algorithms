#include <bits/stdc++.h>
#define ll long
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
//	INPFILE;
	ll t; get(t);
	while(t--) {
		ll n, k;
		get(n); get(k);
		string s;
		cin >> s;
		
		ll ans = 0;
		
		FOR(i,0,n-1)
		 if( s[i] == 'R' )
		 	s[i] = 1;
		 else if( s[i] == 'G' )
		 	s[i] = 0;
		 
		ll toggle = 0;
		queue<ll> ptr;
		
		FOR(i,0,n-1) {
 		 if( !ptr.empty() && i >= ptr.front() )
		 	{ toggle--; ptr.pop(); }
		 if( ( (toggle%2)^s[i] ) ) {
//		 	cout << " P: " << i << endl;
		 	ans++;
		 	toggle++;
		 	ptr.push(i+k);
		 }
		}
		 
		cout << ans << endl;
		 	
	}
}
