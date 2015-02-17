#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define get(a) scanf("%lld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector< pair<ll,double> >::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set< pair< ll, pair<ll,ll> > >::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<ll> >
#define MOD 10000007
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

long a[1000000+5] = {0};

void solve() {
	ll c = 2; ll calc = c*c*c;
	while( calc <= 1000000 )	{
		for( ll i = calc; i <= 1000000; i += calc )
			a[i] = -1;
		c++;
		calc = c*c*c;
	}

	c = 1;
	
	FOR(i,1,1000002) {
		if( a[i] != -1 )
			a[i] = c++;
	}
	
}

int main() {
	solve();
	ll t, count = 1;
	get(t);
	
	while(t--) {
		ll n; get(n);		
		printf("Case %ld: ", count++);
		if( a[n] == -1 )
			printf("Not Cube Free\n");
		else
			printf("%ld\n", a[n]);	
	}

}
