#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define pb push_back
#define min(a,b) a < b ? a : b
#define absol(a) a >= 0 ? a : -a
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
using namespace std;

int main() {
	ll n, w;
	get(n); get(w);
	vector<ll> v;
	v.pb(0);
	
	rep(n) {
		ll x; get(x);
		v.pb(x);
	}
	
	ll maxsum = 0, now = 0; int start = 0;
	for( int end = 0; end < v.size(); end++ ) {
		if( v[end] > w )
			{ now = 0; start = end+1; continue; }
		
		now += v[end];
		
		if( now == w )
		 { maxsum = now;	break; }
		else if( now > w ) {
			while( now > w )
				now -= v[start++];
		}		
		maxsum = now > maxsum ? now : maxsum;				
	}
	
	printf("%lld", maxsum);
}
