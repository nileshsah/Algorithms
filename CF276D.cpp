#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
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
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main() {
	ll l, r;
	cin >> l >> r;
	
	ll val = 0, left = 0, right = 0;
	
	for( ll i = log2(r); i >= 0; i-- ) {
		ll num = (1LL<<i);
		if( (num&l) && (num&r) ) {
		  if( (num^r) >= l )
		   val ^= num;
		}
		else if( (num&l) + (num&r) == 0 ) {
		 if( (num^l) <= r )
		  val ^= num;
		}
		else
		 val ^= num;		 		  
	}
	
	cout << val;
	
}
