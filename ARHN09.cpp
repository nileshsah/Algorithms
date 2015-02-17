#include <bits/stdc++.h>
#define ll long
#define get(a) cin >> a;
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<string>::iterator it = s.begin(); it != s.end(); it++ )
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
#define INF LONG_MAX
using namespace std;

ll sum[1000005] = {0};
ll v[1000005] = {0};

int main() {
	ll n, m;
	cin >> n >> m;
	
	FOR(i,1,n) {
	 cin >> v[i];
	 sum[i] = sum[i-1] + v[i];
	}
	
	FOR(i,1,m) {
		string s; ll l, r;
		cin >> s >> l >> r;
		printf("%ld\n", sum[r] - sum[l-1]);
	}

}
