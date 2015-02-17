#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define MOD 1000000007
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

matrix mul( matrix a, matrix b ) {
	matrix c(2, vector<ll>(2,0) );
	
	FOR(i,0,1)
	 FOR(j,0,1)
	  FOR(k,0,1) {
	  	c[i][j] += ( a[i][k]*b[k][j] )%MOD;
	 	c[i][j] %= MOD;
	 }
	
	return c;  	
}

matrix fastpow( matrix a, ll n ) {
	matrix I(2, vector<ll>(2,0));
	I[0][0] = 1; I[0][1] = 0; I[1][0] = 0; I[1][1] = 1;
	if( n == 0 )
		return I;
	if( n == 1 )
		return a;
	if( n%2 == 0 )
		return fastpow( mul(a,a), n/2 );
	else
		return mul( a, fastpow( mul(a,a), (n-1)/2 ) );		
}


int main() {
	
	matrix v(2, vector<ll>(2,0));
	v[0][0] = 0; v[0][1] = 1; v[1][0] = 1; v[1][1] = 1;

	ll k, m;
	get(k); get(m);
	
	while(m--) {
	  string q; cin >> q;
	  
	  stack<string>  s;
	  s.push("a"); s.push("b");
	  ll maxlen = 3*q.size();
	  ll ans = 0;	  
	  
	  FOR(i,1,maxlen) {
	  	string ptr;
	  	if( i == 1 )
	  	 ptr = "a";
	  	else if( i == 2 )
	  	 ptr = "b";
	  	else {
	  		string top = s.top(); s.pop();
	  		string bottom = s.top(); s.pop();
	  		ptr = top + bottom;
	  		s.push( top ); s.push( ptr );
		}
		
		if( ptr.size() > maxlen )
			break;
		
		cout << " PR: " << ptr << endl;
		if( ptr.find(q) != string::npos ) {
		   matrix adj = fastpow( v, k-i+1 );
		   ans = adj[0][1];
		   break;
		}
			
	  }
		
		printf("%lld\n", ans);
	
	}
}
