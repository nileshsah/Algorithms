#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define foo(a,b,c) mp( mp(a,b), c )
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

string solve( ll n ) {
	queue< pair<string,ll> > q;
	q.push( mp("1",1%n) );
	bool mark[20005] = {0};
	
	while( !q.empty() ) {
		string ptr = q.front().F;
		ll rem = q.front().S;
		q.pop();
		mark[rem%n] = 1;
		
		if( rem%n == 0 )
			return ptr;
		if( !mark[(rem*10)%n] )
		 q.push( mp( ptr+"0", (rem*10)%n ) );
		if( !mark[(rem*10+1)%n] )
	     q.push( mp( ptr+"1", (rem*10+1)%n ) );
	}
}

int main() {
	ll t; get(t);
	while(t--) {
		ll n; get(n);
		printf("%s\n", solve(n).c_str());
	}
}
