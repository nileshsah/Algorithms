#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define get(a) cin >> a
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

ll fastmod( ll x, ll y ) {
	x %= MOD;
	
	if( y == 1 )
		return x;
	if( y == 0 )
		return x;
	if( y%2 == 0 ) {
		ll a = fastmod( x, y/2 )%MOD;
		return (a*a)%MOD;
	}
	else return ( x*fastmod( x, (y-1)/2 ) )%MOD;
}

int main() {
	ll t, k;
	cin >> t >> k;
	
	ll arr[100000+5] = {0}, ans[100000+5] = {0};
	
	if( k != 1 ) {
	  FOR(i,0,k)
		{ arr[i] = 1; }
	  ans[1] = arr[1];
	  FOR(i,2,k)
	 	ans[i] = ans[i-1] + arr[i];
	 	
	  FOR(i, k, 100005)
	   { arr[i] = ( arr[i-1] + arr[i-k] )%MOD; ans[i] = ( ans[i-1] + arr[i] )%MOD; }
	  
	  arr[0] = 0;
	  ans[0] = 0;
	}
	else if( k == 1 ) {
		ll x = 2; ans[0] = 0;
		FOR(i,1,100005)
		  { ans[i] = ( x + ans[i-1] )%MOD; x *= 2; x %= MOD; }
	}
	
	while(t--) {
		ll a, b;
		cin >> a >> b;
		ll val;
		
	    val =  ans[b] - ans[a-1];
		
		if( val >= 0 )
			cout << val << endl;
		else
			cout << val + MOD << endl;
	}
	
}
