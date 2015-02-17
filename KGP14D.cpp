#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for( vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define max(a,b) ( (a > b) ? a : b )
#define min(a,b) ( (a < b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define INPFILE freopen("input.in","r",stdin)
using namespace std;
 
vector< pair<ll,ll> > v;
map<long long unsigned, long> dp;
 
	
ll rec( ll r, ll start, long long unsigned k ) {
	if( dp.find(k) != dp.end() )
		return dp[k];
		
	ll val = 0;
	
	FOR(i,0,v.size()) {
	 if( v[i].F >= start && ( k&(1<<i) ) == 0 ) {
	 	k += 1<<i;
	 	val = max( val, 1 + rec( i, start+v[i].S, k ) );
	 	k -= 1<<i;
	 }
	}
	
	dp[k] = val;
	
//	cout << " REC: " << r << " " << start << " = " << val<< endl;
	return val;
	
}
 
int main() {
//	INPFILE;
	ll t, c= 1; get(t);
	while(t--) {
		ll n; get(n);
		ll dur[105] = {0};
		ll T[105] = {0};
		v.clear();
		dp.clear();
		
		rep(n)
		  get(dur[i]);
		rep(n)
		  get(T[i]);
		
		ll local = 0;
		
		rep(n) {
			pair<ll,ll> p;
			
			if( T[i] == -1 )
			  { local++; continue; }
			p.F = T[i] - 30 - dur[i];
			
			if( p.F < 0 ) continue;
			
			p.S = dur[i];
			v.pb(p);
		}
		
//		sort( all(v) );
	
	
	  if( v.empty() )
		{ printf("Case %ld: %ld\n", c++, n-local); continue; }
			
	   long long unsigned k = 0;
	   printf("Case %ld: %ld\n", c++, n-rec(-1,0,k)-local);
			
			
	}
} 
