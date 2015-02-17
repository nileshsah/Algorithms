#include <bits/stdc++.h>
#include <cstdio>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector< pair<ll,ll> >::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set< pair< ll, pair<ll,ll> > >::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

map<ll,ll> attr[1000000+5];
map<ll,ll> pri[1000000+5];

int main() {
	ll n, m;
	get(n); get(m);
	
	rep(n) {
		ll id, at, val, p;
		get(id); get(at); get(val); get(p);
		
		if( pri[id][at] <= p )
			{ attr[id][at] = val; pri[id][at] = p; }
	}
	
	rep(m) {
		ll id, att;
		get(id); get(att);
		printf("%ld\n", attr[id][att]);
	}
}
