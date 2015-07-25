#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
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
	ll n;
	string s;
	cin >> n >> s;
	
	bool mark[200] = {0};
	string v[50];
	ll ptr = 0;
	
	FOR(i,0,s.size()-1)
	 if( !mark[s[i]] ) {
	 	ptr++;
	 	mark[s[i]] = 1;
	    if( ptr < n )
	 	 v[ptr] += s[i];
	 	else {
	 	 v[ptr] += s.substr(i);
	 	 break;
	 	}
	 }
	 else
	  v[ptr] += s[i];
	 
	 if( ptr == n ) {
	 	cout << "YES\n";
	  FOR(i,1,ptr)
	    cout << v[i] << "\n";
	 }
	 else
	  cout << "NO";
	   
	 	
	
}
