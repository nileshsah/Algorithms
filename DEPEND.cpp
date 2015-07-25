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
#define debug(x) cout << "[DEBUG]" << #x << " " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

map< string, ll > mask;
ll counter = 0;
set<ll> v[10005];
bool visit[10005] = {0};
bool cycle[10005] = {0};
bool node[10005] = {0};
stack<ll> s;


bool dfs( ll x ) {
	
	bool val = 1;
	visit[x] = 1;
	cycle[x] = 1;
	
	if( !node[x] )
		return 0;
		
	repVector(v[x]) {
	 if( !visit[*it] )
	   val *=  dfs(*it);
	 if( cycle[*it] )
	 	val = 0;
	}
	
	cycle[x] = 0;
	
	if(val)
	 s.push(x);
	
//	cout << "REC: " << x << " " << val << endl;
	return val;
}

ll fetch( string s ) {
	if( mask.find(s) != mask.end() )
		return mask[s];
	else
		return mask[s] = ++counter;
}



int main() {
//	INPFILE;

	char str[10000];
	
	while( scanf("%s", &str) != -1 ) {
		ll c = fetch(string(str));
	  while(1) {
	  	node[c] = 1;
		
		char ptr[10000];
	  	scanf("%s", &ptr); 
	  	
	  	if( ptr[0] == '0' )
	  		break;
	
		ll r = fetch(string(ptr));	 	
//	  	cout << "Edge: " << c << " " << r << endl;
		v[c].insert(r);	  	
	 }
	}
	
	bool ans[10005] = {0};
	
	FOR(i,1,counter)
	 if( node[i]  ) {
	 	memset( visit, 0, sizeof visit );
	 	while( !s.empty() ) s.pop();
	 	
	 	bool check = dfs(i);
	 	while( check && !s.empty() ) {
	 	  ans[s.top()] = 1;
	 	  s.pop();
	 	}
	}
	
	ll val = 0;
	
	FOR(i,1,counter)
	 val += ans[i];
	
	cout << val;
   
}
