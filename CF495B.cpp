#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 0; i < n; i++ )
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
	ll a, b;
	cin >> a >> b;
	
	ll val = a - b;
	
	if( val == 0 )
	  { cout << "infinity"; return 0; }
	
	ll end = sqrt(val);
	ll ans = 0;
	
	FOR(i,1,end)
	  if( val%i == 0 ) {
	  	 ll x = i;
	  	 ll y = val/x;
	  	 
	  	 if( x == y && a%x == b )
	  	 	{ ans++; continue; }
	  	 if( a%x == b )
	  	 	ans++;
	  	 if( a%y == b )
	  	 	ans++;
	  	 
	  //	 cout << i << " " << ans << endl;
	  }
	  
	  cout << ans;
}
