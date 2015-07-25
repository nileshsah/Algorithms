#include <bits/stdc++.h>
#define ll int
#define get(a) scanf("%ld", &a);
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define FOR(i,a,b) for( ll i = (a); i <= (b); i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int v[5001][5001] = {0};

int main() {
	BOOST;
	ll n, m;
	cin >> n >> m;
	
	char s[n+1][m+1];
	FOR(i,1,n) 
	 FOR(j,1,m)
	  cin >> s[i][j];
	 
	FOR(i,1,n) {
		ll last = 0;
	 ROF(j,m,1) {
	  ll val = 0; 
	  if( s[i][j] == '0' )
	   { last = val; continue; }
	  val = last + 1;
	  v[j][val]++;
	  last = val;
 	 }
 	}
 	
 	ll ans = 0;
 	FOR(i,1,m) {
 	   ll k = 0;
 	  ROF(j,m-i+1,1)
	   if( v[i][j] ) {
	   	k += v[i][j];
	   	ans = max( ans, j*k );
	   }	   	   
	}
	  
		
	cout << ans;
	
}
