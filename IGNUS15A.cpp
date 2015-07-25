#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define MOD 1000000007
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

ll dp[35][35][35][35];
string a, b, c, d;
ll N;

ll lcs( ll w = 0, ll x = 0, ll y = 0, ll z = 0 ) {
	if( x >= N || y >= N || w >= N || z >= N )
		return 0;
	if( dp[w][x][y][z] != -1 )
		return dp[w][x][y][z];
			
	if( a[w] == b[x] && a[w] == c[y] && a[w] == d[z] ) 
		dp[w][x][y][z] = 1 + lcs(w+1,x+1,y+1,z+1);
	else {
		ll plus = 0;
	
		plus = max( plus, lcs( w+1, x, y, z ) );
		plus = max( plus, lcs( w, x+1, y, z ) );
		plus = max( plus, lcs( w, x, y+1, z ) );
		plus = max( plus, lcs( w, x, y, z+1 ) );
	
		dp[w][x][y][z] = plus;
	}
	
//	cout << " REC: " << w << " " << x << " " << y << " " << z << " = " << dp[w][x][y][z] << endl;

	return dp[w][x][y][z];		
}


int main() {
//	INPFILE;
	ll t; get(t);
	while(t--) {
		memset( dp, -1, sizeof dp );
		get(N);
	
        cin >> a >> b >> c >> d;
	
		cout << lcs() << endl;
	}
}
