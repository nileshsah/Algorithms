#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( auto it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

int main() {
	ll n; cin >> n;
	if( n == 1 )
	 cout << "1";
	else if( n == 2 )
	 cout << "2";
	else if( n == 3 )
	 cout << "6";
	else if( n%2 )
	 cout << n*(n-1)*(n-2);
	else {
        if( n%3 == 0 )
		 cout << (n-1)*(n-2)*(n-3);
		else
		 cout << n*(n-1)*(n-3);                                    
	}
}
