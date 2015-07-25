#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
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
	ll n; cin >> n;
	vector<ll> v;
	FOR(i,1,n)
	 { ll x; cin >> x; v.pb(x); }
	sort( all(v) );
	
	ll dif = v[1] - v[0];
	
	if( n == 1 )
	 { cout << "-1"; return 0; }
	else if( n == 2 && dif%2 == 0)	 { 
	 set<ll> s; 
	 s.insert(v[0]-dif);
	 s.insert(v[0]+dif/2);
	 s.insert(v[1]+dif);
	 cout << s.size() << "\n";
	 repSet(s)
	  cout << (*it) << " ";
	 return 0;
	}
	
	ll diff[2] = {0}, c[2] = {0};
	diff[0] = diff[1] = LLONG_MAX;
	ll nc = 0;
	 
	for( ll i = 1; i < v.size(); i++ ) {
	  ll p = v[i] - v[i-1];
	  if( diff[0] == p )
	   c[0]++;
	  else if( diff[1] == p )
	   c[1]++;
	  else if( diff[0] == LLONG_MAX )
	   { diff[0] = p; c[0]++; nc++; }
	  else if( diff[1] == LLONG_MAX )
	   { diff[1] = p; c[1]++; nc++; }
	  else {
	  	cout << "0"; return 0; 
	  }

	}
	
	if( c[0] > 1 && c[1] > 1 )
	 { cout << "0"; return 0; }
	
	 if( c[0]==0 || c[1]==0) {
	 	ll i = 0;
		 set<ll> s; 
		 s.insert(v[0]-diff[i]);
		 s.insert(v.back()+diff[i]);
		 cout << s.size() << "\n";
		 repSet(s)
		  cout << (*it) << " ";
		 return 0;
	}	 	
	 
	FOR(i,0,1)
	 if( c[i] == 1 && diff[i]%2 == 0 && diff[i]/2 == diff[!bool(i)]) { 
	   cout << "1\n";
	   for( ll j = 1; j < v.size(); j++ )
	    if( v[j] - v[j-1] == diff[i] )
	      { cout << v[j-1] + diff[i]/2; return 0; }
	 }
	 
	 cout << "0";
}
