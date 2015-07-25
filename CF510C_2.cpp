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

vector<ll> adj[200];
bool cycle[200] = {0};
bool explore[200] = {0};
queue<ll> s;

void dfs( ll x ) {
	explore[x] = 1;
	cycle[x] = 1;
	
	repVector(adj[x]) {
	 if( !explore[*it] )
	   dfs(*it);
	 if( cycle[*it] )
	  { cout << "Impossible" ; exit(0); }
	}
	
	cycle[x] = 0;
	s.push(x);
}

int main() {
//	INPFILE;
	ll n; get(n);
	vector<string> v;
	
	FOR(i,1,n) {
		string s;
		cin >> s;
		v.pb(s);
	}
	
	FOR(i,0,n-1)
	 FOR(j,i+1,n-1) {
	 	bool flag = 0;
	  FOR(k,0,min(v[i].size(),v[j].size())-1)
	    if( v[i][k] != v[j][k] ) {
	    	flag = 1;
	    	adj[v[j][k]].pb(v[i][k]);
//	    	cout << v[j][k] << " " << v[i][k] << "\n";
	    	break;
	    }
	    if(!flag && v[j].find(v[i]) == string::npos )
	     { cout << "Impossible"; return 0; }
	 }
	 
	 string ans = "";
	 
	 FOR(i,'a','z') 
	  if(!explore[i]) {
	 	dfs(i);
	 	while( !s.empty() )
	 	 { ans += char(s.front()); s.pop(); }
	 }
	  
	  cout << ans;
	
}
