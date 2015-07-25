#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
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
#define MOD 1000000007
using namespace std;

vector<ll> v;
ll n, k;

bool check( ll x ) {
    ll left = x, monks = k-1, last = v[0] + x;
   
    FOR(i,1,n-1) {
     if(  v[i] - last > x )
       {  monks--; last = v[i] + x; }
     if( monks < 0 )
       return 0;
     }
     
     return 1;
}

ll search( ll start, ll end ) {
	ll mid = ( start + end )/2;
	
	if( start > end )
	  return start;
	if( check(mid) )
	 return search( start, mid-1 );
	else
	 return search( mid+1, end );
}


int main() {
  cin >> n >> k;
  
  FOR(i,1,n) 
   { ll x; cin >> x; v.pb(x); }
  sort( all(v) );
  
  
  cout << search( 1, 20000000 );
    
}
