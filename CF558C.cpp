#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
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
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main() {
	ll n; cin >> n;
	vector<ll> v; vector<string> str;
	FOR(i,1,n) {
	  ll x; cin >> x; v.pb(x);
	  string s; bool flag = 0;
	  while(x) { 
	   if( (x&1) || flag ) 
	    { flag = 1; s.pb( x%2 + '0' ); }
	   x /= 2; 
	  }
	  reverse( all(s) );
	  debug(s);
	  str.pb(s);
	}
	
	if( n == 1 )
	 { cout << "0"; return 0; }
	 
	string ptr;
	FOR(i,0,min(str[0].size(),str[1].size())-1)
	 if( str[0][i] == str[1][i] )
	  ptr.pb(str[0][i]);
	 else
	  break;
	
	FOR(i,2,str.size()-1) {
	  string tp;
	 FOR(j,0,min(str[i].size(),ptr.size())-1)
	 	if( ptr[j] == str[i][j] )
	 		tp.pb(ptr[j]);
	 	else
	 	    break;
	   ptr = tp;
	}
	
	
	bool mflag = 1;
	ll eq = 0, ans = 0;
	vector<ll> zero;
	
	FOR(i,0,n-1)  {
	 	ll x = v[i], z = 0;
	 	while( x && !(x&1) )
	 	 { eq++; x /= 2; z++; }
	 	zero.pb(z);
	}
	
	debug(eq);
	debug(ptr);

	 ll lower = eq/n;
	 ll upper = ceil(1.0*eq/n);
	 
	// cout << lower << " " << upper << "\n";
	 
	 ll lans = 0, uans = 0;
	 
	 FOR(i,0,zero.size()-1) {
	 	ll z = 0;
	 	FOR(j,ptr.size(),str[i].size()-1)
	 	 if( str[i][j] == '0' )
	 	  z++;
	  lans += abs(zero[i]+z-lower) + (str[i].size()-ptr.size()-z);
	  uans += abs(zero[i]+z-upper) + (str[i].size()-ptr.size()-z);
	  debug(lans); debug(uans);
	 }
	
	 cout << min(lans,uans);

	 
	 	
	  
	
}
