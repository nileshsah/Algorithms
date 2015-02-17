#include <bits/stdc++.h>
#include <cstdio>
#define ll long
#define llu long long unsigned
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSTL(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
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

ll isCube[1000000+5] = {0};

struct node {
	ll a, b, c, d;
};

bool compare( const node &a, const node &b ) {
	if( a.a < b.a )
		return a.a < b.a;
	else if( a.a == b.a )
		return a.b < b.b;
	return false;
}


int main() {
	ll n = 100;
	
	FOR(i,2,n)
		isCube[i*i*i] = i;
	
	vector<node> v;
	
	FOR(i,2,n)
	 FOR(j,i+1,n) {
	  FOR(k,j+1,n) {
	  	ll val = i*i*i + j*j*j + k*k*k;
	  	if( val > 1000000 )
	  		break;
	  	if( isCube[val] ) {
	  		node p;
	  		p.a = isCube[val]; p.b = i; p.c = j; p.d = k;
	  		v.pb(p);
		}
	  	  
	  }
	  
	  if( i*i*i + j*j*j > 1000000 )
	  	break;
	}
	
	sort( all(v), compare );
	
	FOR(i,0,v.size()-1)
		printf("Cube = %ld, Triple = (%ld,%ld,%ld)\n", v[i].a, v[i].b, v[i].c, v[i].d);
	  
	  	
}
