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
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;


set<string> idx;
bool flag = 0;
string last;

bool cmp( string a ) {
	if( last.size() > a.size() )
		return 0;
	if( last.size() == a.size() )
	  FOR(i,0,last.size()-1)
	   if( a[i] > last[i] )
	   	return 1;
	   else if( a[i] < last[i] )
	   	return 0;
	
	if( a.size() > last.size() )
		return 1;
}

bool getnum( ll d, ll val, string s ) {
	
	if( flag )
	 return 1;
//	cout << " REC: " << d << " - " << val << " = " << s << endl;
	 if( d < 0 ) {
	 	if( !cmp(s) )
	 		return 0;
	 }
	 if( d < 0 && idx.count(s) == 0 )
	 	{ idx.insert(s); last = s; cout << s << endl; flag = 1; return 1; }
	
		 FOR(j,0,9)
		  if( s.empty() && j == 0 ) continue;
		  else if( flag ) return 0;
		  else if( val - j <= 9*d && val - j >= 0 ) {
		  	string temp = s; temp.pb( char(j+'0') );
		  	getnum( d-1, val-j, temp );
		  }		  	
}

int main() {
	ll n; cin >> n;
	vector<ll> v;
		
	FOR(i,1,n)
	 { ll x; cin >> x; v.pb(x); }
	last = "0";
	
	for( ll i = 0; i < v.size(); i ++ )
	  FOR(j,v[i]/9+1 - (v[i]%9 == 0 ),100) {
	  	flag = 0;
	    getnum( j-1, v[i], "" );
	    if( flag )
	   	 break;
	  }
	  
}
