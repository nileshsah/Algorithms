#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define max(a,b) ( (a > b) ? a : b )
#define min(a,b) ( (a < b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

vector<ll> v[55];
bool mark[55] = {0};
ll ans = 1;


void dfs( ll r ) {
	mark[r] = 1;
	
	repVector(v[r])
	 if( !mark[*it] ) {
	 	ans *= 2;
		dfs(*it);
	 }
	 	
}


int main() {
	//INPFILE;
	ll n, m;
	cin >> n >> m;	
	
	if( m == 0 )
	 { cout << "1"; return 0; }

 
	rep(m) {
	   ll x, y;
	   get(x); get(y);
	   v[x].pb(y); v[y].pb(x);
	}
	
	FOR(i,1,n)
	  if( !mark[i] )
	  	dfs(i);
	
	cout << ans;
	 
	 
}

