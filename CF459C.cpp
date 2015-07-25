#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
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


ll n, k, d;
ll cc = 0;
vector< vector<ll> > s;

void genx( vector<ll> v, ll ptr ) {
	s.pb(v);
	if( s.size() >= n )
	 return;
		
	FOR(i,ptr,d)
	 if( s.size() >= n )
	 	return;
	 else if( v[i] < k ) { 
	 	v[i]++;
	 	genx( v, i );
	 	v[i]--;
	 }

	 		  
}

	
int main() {
	cin >> n >> k >> d;
	
	ll ptr = 0, ltr = 1, idx = 0;
	bool flag = 0;
	
	while( ptr <= d ) {
	 if( ltr >= n )
	  { flag = 1; break; }
	 ltr *= k; ptr++;
	}
	
	if(!flag)
	 { cout << "-1"; return 0; }
	
	vector<ll> v;
	FOR(i,1,n) {
	  idx %= k; idx++;
	  v.pb(idx);
	}


	genx(vector<ll>(d+1,1),1);
	
	
	FOR(i,1,d) {
	  auto it = s.begin();
	 FOR(j,1,n) {
	  cout << (*it)[i] << " ";
	  it++;
	 }
	 cout << "\n";
	}
	  
		
	 	
}
