#include <bits/stdc++.h>
#define ll long
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

int main() {
	ll t; get(t);
	while(t--) {
		ll n; get(n);
		string s;
		cin >> s;
		
		ll pos; char ptr;
		ll ini;
		set<string> v;
		
		FOR(i,0,n-1)
		 FOR(j,0,n-1) {
		   if( i == j ) continue;
		 	string temp = s;
		 	string p(1,s[i]);
		 	temp.erase(i,1);
		 	temp.insert(j,p);
		 	
		 	v.insert(temp);
		 }
		 
		 if( n == 1 )
		   cout << s << endl;	
		 else
		 cout << min(s,*v.begin()) << endl;
		
		  	
	}
}
