#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
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

vector<ll> v;

int main() {
//	INPFILE;
	ll n; cin >> n;
	FOR(i,1,n)
	 { ll x; cin >> x; v.pb(x); }

	ll maxsum = 0;
	
	FOR(i,0,n-1) {
		ll itr = i+1;
	ROF(k,n-1,max(i+1,n-10)) {
		ll sum = 0, ptr = i;
	 ROF(j,k,i+1) {
	 	sum += v[ptr++]*v[j];
	 //	debug(sum);
	 	if( sum <= 0 || ptr > j )
	 	 { sum = 0; ptr = i; }
	 	maxsum = max( maxsum, sum );
	 }
	}
	}
	
	cout << maxsum;
	
}
