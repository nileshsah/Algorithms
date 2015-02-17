#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%d", &a);
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
	ll n, m;
	cin >> n >> m;
	
	bool mark[500005] = {0};
	ll a = n;
	
	while(1) {
		if( a%m == 0 )
		 { cout << "Yes"; return 0; }
		if( mark[a%m] == 1 )
		  { cout << "No"; return 0; }
		mark[a%m] = 1;
		a += a%m;
	}
	
}
