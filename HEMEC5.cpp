#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
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
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

ll dp[1000005] = {0};
bool pan[1000005] = {0};


bool rec( ll n ) {
	if( pan[n] )
	 return 1;
	if( dp[n] != -1 )
	 return dp[n];

	bool val = 0;

	ll m = n;
	set<ll> dig;
	while(m)
	 { if( m%10 ) dig.insert((m%10)*(m%10)); m /= 10; }
	 
	repVector(dig)
	 if( val )
	  return dp[n] = val;
	 else if( n - (*it) > 0 )
	  val |= rec( n-(*it) );
	  
	return dp[n] = val;
}

int main() {
	vector<ll> v; ll p = 1;

	while( pow(p,p) <= 1000000 ) {
		pan[ (long long)pow(p,p) ] = 1; p++;
	}
		
	memset( dp, -1, sizeof dp );
	
	FOR(i,1,1000000)
	 rec(i);
	
	ll t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		bool flag = rec( n );
	
	
		if(flag)
		 cout << "Yes\n";
		else
		 cout << "No\n";
	}
}
