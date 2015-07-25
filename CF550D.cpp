#include <bits/stdc++.h>
#define ll int
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
	BOOST;
	ll k; cin >> k;
	
	if( !(k%2) )
	 { cout << "NO"; return 0; }
	if( k == 1 )
	 { cout << "YES\n2 1\n1 2"; return 0; }
	
	cout << "YES\n";
	
	ll n = k+2;
	ll arr[500] = {0};
	FOR(i,1,k+2)
	 arr[i] = k;
	
	cout << 2*k+4 << " " << k*(k+2) << "\n";
	cout << "1 " << k+3 << "\n";
	cout << "1 2\n" << k+3 << " " << k+4 << "\n";
	arr[1] -= 2; arr[2]--;
	
	ll cc = 3;
	
	FOR(i,2,k+2)
	 FOR(j,1,arr[i]) {
	 	ll num = k+2;
	 	ll ptr = (i+j)%(num+1);
	 	if( ptr == 0 ) ptr++;
	 	
	 	arr[ptr]--;
	 	cout << i << " " << ptr << "\n";
	 	cout << i+k+2 << " " << ptr+k+2 << "\n";
	 	cc += 2;
	 }
	  
	  debug(cc);
	
}
