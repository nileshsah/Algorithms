#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define get(a) cin >> a
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector< pair<ll,ll> >::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set< pair< ll, pair<ll,ll> > >::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

bool m[100005] = {0};


int main() {
	ll n, k;
	cin >> n >> k;
	
	ll val = 1;
	ll num = 0;
	ll count = n;
	ll tmp = 1;
	
	ll ans[100005] = {0};
	
	for( ll i = 1; i <= n; i += 2 )
		ans[i] = i;
		
}
