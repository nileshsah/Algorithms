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
#define MOD 1000000007
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

int main() {
	string s,p;
	cin >> s;
	
	p += s[0];
	ll last = 0;
	bool behind = 0;
	
	FOR(i,1,s.size()-1) {
	   if( p.size() > 1 && s[i] == p.back() && behind  )
	    continue; 
	   if( s[i] == p.back() && last == 1 )
	    continue;
	   if( p.back() != s[i] && last == 1 )
	     behind = 1;
	   else
	     behind = 0;
	     
	      if( s[i] == p.back() )
	   	   last++;
	   	 else
	   	   last = 0;
	   	 p += s[i];
	   }
	   	 
	   	   
	 cout << p;
}
