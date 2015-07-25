#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define MOD 1000000007
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

ll mod = 0;

ll modpow(ll a, ll n )
{
    ll ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ret;
}

map< pair<ll,ll>, bool > idx;

int main() {
	ll m; cin >> m;
	mod = m;
	ll h1, h2, a1, a2, x1, y1, x2, y2;
	cin >> h1 >> a1;
	cin >> x1 >> y1;
	cin >> h2 >> a2;
	cin >> x2 >> y2;
	
	ll lasth1 = y1;
	ll lasth2 = y2;
	ll i = 0;
	
	while(1) {
	  i++;
	 if( idx[ mp( ( lasth1 + modpow(x1,i)*h1 )%m, ( lasth2 + modpow(x2,i)*h2 )%m ) ] )
	   { cout << "-1"; return 0; }
	 if( ( lasth1 +  modpow(x1,i)*h1 )%m == a1
	     && ( lasth2 + modpow(x2,i)*h2 )%m == a2 )
	   { cout << i; return 0; }	
	 idx[ mp( ( lasth1 + modpow(x1,i)*h1 )%m, ( lasth2 + modpow(x2,i)*h2 )%m ) ] = 1;
	 lasth1 = ( lasth1*x1 + y1 )%m;
	 lasth2 = ( lasth2*x2 + y2 )%m;
	}
	
	cout << "-1";
	
	
}
