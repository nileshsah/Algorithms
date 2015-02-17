#include <bits/stdc++.h>
#define ll long long
#define get(a) cin >> a;
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

ll arr[300005] = {0};


int main() {
//	INPFILE;
	ll n; cin >> n;
	vector<ll> v;
	v.pb(0);
	
	ll sum = 0;
	
	FOR(i,1,n)
	 { ll x; cin >> x; v.pb(x); }
	
	sort( all(v) );
	
	for( ll i = v.size()-1; i >= 1; i-- )
		arr[i] = v[i] + arr[i+1];
	
	FOR(i,1,n)
	 sum += v[i-1] + arr[i];
	
	cout << sum;
	
	

}
