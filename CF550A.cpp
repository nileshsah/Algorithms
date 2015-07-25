#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( auto it = s.begin(); it != s.end(); it++ )
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
using namespace std;

int main() {
	string s;
	cin >> s;
	
	ll aba = 0, ab = 0, ba = 0;
	FOR(i,0,s.size()-1)
	 if( s[i] == 'B' )
	  if( i > 0 && i < s.size()-1 && s[i-1] == 'A' && s[i+1] == 'A' )
	    aba++;
	  else if( i < s.size()-1 && s[i+1] == 'A' )
	    ba++;
	  else if( i > 0 && s[i-1] == 'A' )
	    ab++;
	
   if( ( ab > 0 && ba > 0 ) || ( aba > 0 && ( ba > 0 || ab > 0 ) ) || aba >= 2 )
      cout << "YES";
   else 
      cout << "NO";
}
