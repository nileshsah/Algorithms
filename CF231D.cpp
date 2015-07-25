#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%lld", &a);
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
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
	ll x, y, z;
	cin >> x >> y >> z;
	ll a, b, c;
	cin >> a >> b >> c;
	ll A, B, C, D, E, F;
	cin >> A >> B >> C >> D >> E >> F;
	
	ll ans = A*(y<0) + B*(y>b) + C*(z<0) + D*(z>c) + E*(x<0) + F*(x>a);
	cout << ans;
}
