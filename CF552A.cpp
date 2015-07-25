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
	ll n; cin >> n;
	ll arr[105][105] = {0};
	
	FOR(i,1,n) {
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		FOR(p,x1,x2)
		 FOR(q,y1,y2)
		  arr[p][q]++;
	}
	
	ll ans = 0;
	FOR(i,1,100)
	 FOR(j,1,100)
	  ans += arr[i][j];
	
	cout << ans;
}
