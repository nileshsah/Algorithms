#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define MOD 1000000007
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

int main() {
	ll t; get(t);
	while(t--) {
		string s;
		cin >> s;		
		char ptr[] = { '+', '-' };
		ll x = 0, y = 0, idx, kdx;
		
		idx = 0; kdx = 1;
		FOR(i,0,s.size()-1) {
		 if( s[i] != ptr[idx] )
		 	x++;
		 if( s[i] != ptr[kdx] )
		 	y++;
		 idx ^= 1; kdx ^= 1;
		}
		
		printf("%lld\n", min(x,y));
	}
}
