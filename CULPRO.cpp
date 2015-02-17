#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
#include <algorithm>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector< pair<ll,ll> >::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set< pair< ll, pair<ll,ll> > >::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
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

int main() {

	ll n; get(n);
	vector< pair<ll,ll> > v;
	set<ll> s;
	
	rep(n) {
		ll x, y;
		get(x); get(y);
		v.pb( mp( min(x,y) , max(x,y) ) );
	}
	
	sort( all(v) );
	
	ll ans = 0, count = 0;
	
	FOR(i,0,v.size()) {
		while( !s.empty() && *s.begin() <= v[i].F )
		 {  count--; s.erase(s.begin()); }
		count++; s.insert(v[i].S);
		//cout << v[i].F << " " << v[i].S << " -> " << count << endl;
		ans = max( count, ans );
	}
	
	printf("%ld\n", ans);

}
