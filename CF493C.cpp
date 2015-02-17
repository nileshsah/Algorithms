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

int main() {
	vector<ll> a,b;	
	ll n, m; 
	
	get(n);
	rep(n) { ll x; cin >> x; a.pb(x); }
	
	get(m);
	rep(m) { ll x; cin >> x; b.pb(x); }
	
	sort( all(a) );
	sort( all(b) );
	
	a.pb(LLONG_MAX); b.pb(LLONG_MAX);
	
	ll p,q; 
	p = q = 0;
	
	ll ansA, ansB, ans;
	ans = n*3 - m*3;
	ansA = n*3; ansB = m*3;
	
	if( ans < n*2 - m*2 ) {
		ans = n*2 - m*2;
		ansA = n*2; ansB = m*2;
	}
	
	while( a[p] != LLONG_MAX ) {
		if( a[p] < b[q] )
		  do {
			p++;
		 }while( a[p] == a[p-1] );
		else if( a[p] > b[q] )
		 do {
			q++;
		 }while( b[q] == b[q-1] );
		else if( a[p] == b[q] )
			{ p++; q++; }
			 
		ll A = p*2 + (n-p)*3;
		ll B = q*2 + (m-q)*3;
		ll val = A - B;
		
		//cout << val << " A: " << A << " B: " << B << endl;
		if(  val > ans || ( val == ans && ansA < A ) )
		  { ans = val; ansA =  A; ansB = B; }

	}
	
	cout << ansA << ":" << ansB;
	
}
