#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
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
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main() {
//	INPFILE;
	ll t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		ll arr[n+1][n+1];
		ll vertical[100][100] = {0};
		ll horizontal[100][100] = {0};

		
		FOR(i,1,n)
		 FOR(j,1,n)
		  cin >> arr[i][j];
		  
		FOR(i,1,n)
		 FOR(j,1,n) {
		  horizontal[i][j] = horizontal[i][j-1];
		  horizontal[i][j] ^= arr[i][j];
		  vertical[j][i] = vertical[j-1][i];
		  vertical[j][i] ^= arr[j][i];
		}
		
		ll maxval = 0;
		
		FOR(x1,1,n)
		 FOR(y1,1,n)
		  FOR(x2,x1,n) {
		  	ll val = 0;
		   FOR(y2,y1,n) {
		    val ^= horizontal[y2][x2];
			val ^= horizontal[y2][x1-1];
		    
//		    cout << x1 << " " << y1 << " " << x2 << " " << y2 << " = " << val << "\n";
		    maxval = max( maxval, val );
		   }
		}
		
		cout << maxval << "\n";
	}
}
