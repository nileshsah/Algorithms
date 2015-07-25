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

int main() {
	ll t; get(t);
	while(t--) {
	   ll n; get(n);
	   vector<ll> v;
	   FOR(i,1,n)
	    { ll x; get(x); v.pb(x); }
	   
	   ll sum = 0, maxsum = -1500, ans = 0;
	   FOR(i,0,n-1) {
	     sum = max( v[i], v[i]+sum );
	     maxsum = max( maxsum, sum );
	   }
	   
	   sum = 0; ll len = 0, zc = 0;
	   FOR(i,0,n-1) {
	     if( v[i] < v[i]+sum )
	       sum += v[i];
	     else if( v[i] > v[i]+sum )
	       zc = 1, sum = v[i];
	     else
	       zc++, sum = v[i];
	     
	     
	     if( sum == maxsum )
	       {  ans += zc; }	       
	   }
	    
	    printf("%lld %lld\n",maxsum,ans);
	}
}
