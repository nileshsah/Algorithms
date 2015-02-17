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

bool mark[100005] = {0};
vector<ll> v[100005];
bool explore[100005] = {0};

ll ans = 0;

ll dfs( ll x ) {
	explore[x] = 1;
	ll val = 0;
	
	if( mark[x] )
		val++;
	
	repVector(v[x])
	 if( !explore[*it] )
	 	val +
		 = dfs(*it);
	cout << val << endl;
	
	ans += val;
		
	return val;
}

int main() {
	INPFILE;
	ll n; cin >> n;
	
	FOR(i,1,n-1)
	 { ll x; get(x); v[i].pb(x); v[x].pb(i); }
	
	FOR(i,0,n-1)
	 cin >> mark[i];
	
	dfs(0);
	cout << " ANS: " << ans;
}
