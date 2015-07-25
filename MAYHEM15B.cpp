#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( auto it = s.begin(); it != s.end(); it++ )
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

int main() {
	ll t; cin >> t;
	while(t--) {
		ll n, k;
		cin >> n >> k;
		string str[n+1];
		FOR(i,1,n)
		 cin >> str[i];
	   	FOR(i,0,k-1) {
	   		char minc; ll low = INT_MAX;
	   	 FOR(c,'a','z') {
	   	 	ll calc = 0;
	   	  FOR(j,1,n)
	   	    calc += abs( c - str[j][i] );	   	    
	   	   if( calc < low )
	   	    { low = calc; minc = c; }
	   	 }
	       cout << minc;	   
	    }
		cout << "\n";  
	}
}
