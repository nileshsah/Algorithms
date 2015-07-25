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

bool explore[1005][1005] = {0};
char arr[1005][1005];
ll mark[1005][1005] = {0};


ll rec( ll x, ll y, ll idx ) {

	if( explore[x][y] && mark[x][y] == idx )
		return 1;
	else if( explore[x][y] )
		return 0;
		
	explore[x][y] = 1;
	mark[x][y] = idx;
	
	if( arr[x][y] == 'S' )
		return rec( x+1, y, idx );
	if( arr[x][y] == 'W' )
		return rec( x, y-1, idx );
	if( arr[x][y] == 'N' )
		return rec( x-1, y, idx );
	if( arr[x][y] == 'E' )
		return rec( x, y+1, idx );
	
}

int main() {
//	INPFILE;
	
	ll n, m;
	get(n); get(m);
		
	FOR(i,1,n)
	  scanf("%s", arr[i]+1);
	
	ll idx = 1, ans = 0;
	
	FOR(i,1,n)
	 FOR(j,1,m)
	  if( !explore[i][j] )
	   ans += rec( i, j, idx++ );
	
	printf("%ld\n", ans);
	  	
}
