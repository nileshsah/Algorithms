#include <bits/stdc++.h>
#define ll int
#define get(a) scanf("%d", &a)
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

int main() {
//	INPFILE;
	ll n; get(n);
	bitset<2000> bit[2000];
	string s[n];
	
	FOR(i,0,n-1) {
	 cin >> s[i];
	 bit[i] = bitset<2000>(s[i]);
	}
	
	ll ans = 0;
	
	FOR(i,0,n-1)
	 FOR(j,i+1,n-1)
	  if( s[i][j] == '1' ) continue;
	  else if( (bit[i]&bit[j]).any()  ) ans += 2;
	 
	cout << ans;
}
