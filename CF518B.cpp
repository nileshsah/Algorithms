#include <bits/stdc++.h>
#define ll long long
//#define get(a) scanf("%lld", &a);
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

int main() {
	string s, t;
	cin >> s >> t;
	
	ll x[200] = {0}, y[200] = {0};
	
	FOR(i,0,s.size()-1)
		x[s[i]]++;
	FOR(i,0,t.size()-1)
	 	y[t[i]]++;
	
	ll yay = 0, who = 0;
	
	FOR(i,'A','z')
	  if(  x[i] <= y[i] )
	  	{ yay += x[i]; y[i] -= x[i]; x[i] = 0; }
	  else if( x[i] > y[i] )
	    { yay += y[i]; x[i] -= y[i]; y[i] = 0; }
	
	FOR(i,'A','z')
	  if( isupper(i) )
	  	who += min(x[i],y[tolower(i)]); 
	  else if( islower(i) ) 
	    who += min(x[i],y[toupper(i)]);
	 
	cout << yay << " " << who << endl;
}
