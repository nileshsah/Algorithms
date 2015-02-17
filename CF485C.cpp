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
	
//	cout << (long long)pow(2,62);
	ll n; cin >> n;
	while(n--) {
		ll l, r;
		cin >> l >> r;
		
		ll k = 0;
		ll temp = r, count = 0;
		
		while( temp )
		 { temp >>= 1; count++; }
		
//		cout << " C: " << count << endl;
		
		
		for( ll i = count-1; i >= 0; i-- ) {
			ll p = pow(2,i);
		//	cout << " P: " << p << " " << k << endl;
			if( (p&l) && (p&r) )
			   { k += p;  }
			else if( (p&r) && !(p&l) ) {
				FOR(j,0,i-1)
				 k += (long long)pow(2,j);
				if( k + (long long)pow(2,i) <= r )
					k += (long long)pow(2,i);
				break;
			}
		}
			
		cout << k << endl;
	}
	
}
