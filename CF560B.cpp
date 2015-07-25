#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << endl
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
	ll a1, b1, a2, b2, a3, b3;
	cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
	
	if( a1 > b1 ) swap(a1,b1);
	if( a2 > b2 ) swap(a2,b2);
	if( a3 > b3 ) swap(a3,b3);
	
	if( a1 - a2 < 0 || b1 - b2 < 0 || a1 - a3 < 0 || b1 - b3 < 0 )
	 { cout << "NO"; return 0; }
	 
	ll x1 = a1 - a2, y1 = b1;
	ll x2 = a1, y2 = b1 - b2;
	ll x3 = a1 - b2, y3 = b1;
	ll x4 = a1, y4 = b1 - a2;
	
	if( x2 > y2 ) swap(x2,y2);
	if( x1 > y1 ) swap(x1,y1);
	if( x3 > y3 ) swap(x3,y3);
	if( x4 > y4 ) swap(x4,y4);
	
	if( ( x2 >= a3 && y2 >= b3 ) || ( x1 >= a3 && y1 >= b3 ) ||  ( ( x3 >= a3 && y3 >= b3 ) || ( x4 >= a3 && y4 >= b3 ) ) )
	 { cout << "YES"; return 0; }

	cout << "NO";
	
}
