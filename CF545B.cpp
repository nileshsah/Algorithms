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
	string s, t;
	cin >> s >> t;
	
	ll c = 0;
	FOR(i,0,s.size()-1)
	 if( s[i] != t[i] )
	  c++;
	
	if( s == t )
	 { cout << s; return 0; }
	
	if( c%2 != 0 )
	 { cout << "impossible"; return 0; }
	
	ll dt = c/2, ds = c/2;
	
	FOR(i,0,s.size()-1)
	 if( s[i] != t[i] )
	  if( dt >= ds )
	   { cout << t[i]; dt--; }
	  else
	   { cout << s[i]; ds--; } 
	  else
	   cout << s[i];
	  
}
