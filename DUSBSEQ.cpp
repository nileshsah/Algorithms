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

const ll MOD = 1000000007;

ll modpow( ll x, ll y ) {
	ll ans = 1, num = x;
	while(y) {
	   if(y%2)
	    ans = (ans*x)%MOD; 
	   x = (x*x)%MOD;
	   y /= 2;
	}
	return ans;
}

int main() {
	ll t; cin >> t;
	while(t--) {
		string s;
		cin >> s;
		ll mark[150] = {0};
		ll ans = modpow(2,s.size());
		
		FOR(i,0,s.size()-1) {
		 if( mark[s[i]] )
		  ans = ( ans - mark[s[i]]*modpow(2,s.size()-i-1) + 5*MOD )%MOD;
	
		  ans = ( ans + 5*MOD )%MOD;
		  mark[s[i]]++;
		}
		cout << ans << "\n";
		
	}
}
