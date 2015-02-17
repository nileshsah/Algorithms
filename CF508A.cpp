#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
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

int main() {
//	INPFILE;
	bool a[1005][1005] = {0};
	
	ll n, m, k;
	cin >> n >> m >> k;
	
	FOR(i,1,k) {
		ll x, y;
		cin >> x >> y;
		a[x][y] = 1;
		
		bool exp = a[x+1][y] && a[x+1][y+1] && a[x][y+1];
		exp |= a[x-1][y] && a[x-1][y-1] && a[x][y-1];
		exp |= a[x][y-1] && a[x+1][y-1] && a[x+1][y];
		exp |= a[x-1][y] && a[x][y+1] && a[x-1][y+1];
		
		if(exp)
		 { cout << i; return 0; }		
	}
	
	cout << "0";
}
