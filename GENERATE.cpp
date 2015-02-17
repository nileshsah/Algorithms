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
#define gc getchar
#define pc(x) putchar(x);
using namespace std;

int main() {
	freopen("input.in", "w", stdout );
	srand (time(NULL));
	ll n = rand()%111;
	ll m = rand()%111;
	ll k = rand()%1000;
	
	cout << n << " " << m << " " << k << endl;
	FOR(i,1,k) {
		ll x = rand()%(n+1);
		ll xx = rand()%m;
		
		if( x == 0 )
		 xx = 0;
		
		ll y = x + 1 + rand()%(n+1-x);
		if( y > n+1 )
		 y = n+1;
			
		ll yy = rand()%m;
		if( y == n+1 ) yy = 0;
		
		cout << x << " " << xx << " " << y << " " << yy << endl;
	}
}
