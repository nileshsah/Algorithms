#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
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

ll M = 100000007;

ll modpow( ll x, ll y ) {
	if( y <= 0 )
	 return 1;
	if( y == 1 )
		return x;
	if(y%2) {
	  ll q = modpow(x,(y-1)/2);
	  q = q*q; q %= M;
	  q *= x%M; q %= M;
	  return q;
	}
	else {
	  ll q = modpow(x,y/2);
	  q = q*q; q %= M;
	  return q;
	}
	 
}

ll hash( string s ) {
	ll num = 0;
	repVector(s) {
		ll p = *it - 'a' + 1;
		num *= 4;
		num += p;
		num %= M;
	}
	return num;
}


int main() {
	cout << modpow(4,3);
//	std::ios::sync_with_stdio(false);
INPFILE;
	ll n, m;
	cin >> n >> m;
	set<ll> s;
	
	FOR(i,1,n) {
	  string a;
	  cin >> a;
	  s.insert(hash(a));
	}
	
	
	FOR(i,1,m) {
	  string x, y; cin >> x;
	  ll idx = hash(x);
	  
	  FOR(j,0,x.size()-1)
	   FOR(k,'a','c')
	    if( x[j] != k ) {
	    	ll temp = idx - modpow(4,x.size()-1-j)*(x[j]-'a'+1);
	    	temp += modpow(4,x.size()-1-j)*(k-'a'+1);
	        temp = ( temp + 4*M )%M;
	    	if( s.count(temp) )
	    	  { cout << "YES\n"; goto next; }
	    }
	   
	   cout << "NO\n";
	   next:
	     continue;
	}
		
}
