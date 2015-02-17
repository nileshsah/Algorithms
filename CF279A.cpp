#include <bits/stdc++.h>
#include <cstdio>
#define ll int
#define get(a) scanf("%d", &a)
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for(vector< pair<ll,ll> >::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set< pair< ll, pair<ll,ll> > >::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<double> >
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

int main() {
	ll n; get(n);
	ll a[6000] = {0};
	ll cum[4] = {0};
	vector<int> v[4];
	
	rep(n) { get(a[i]);  cum[a[i]]++; v[a[i]].pb(i); }
	
	ll ans = min( cum[1], min( cum[2], cum[3] ) );
	cout << ans << endl;
	
	FOR(i,0,ans-1)
	 cout << v[1][i] << " " << v[2][i] << " " << v[3][i] << endl;
	
	
	
}
