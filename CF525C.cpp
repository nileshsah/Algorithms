#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
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
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

ll cnt[1000005] = {0};
ll mcnt[1000005] = {0};

int main() {
	ll n; cin >> n;
	ll maxx = 0;
	
	FOR(i,1,n) {
	   ll x; cin >> x;
	   cnt[x]++;
	   mcnt[x]++;
	   maxx = max(maxx,x);
	}
	
	ROF(i,maxx,1) {
		if( cnt[i]%2 && mcnt[i] > 0 )
		 { cnt[i-1]++; cnt[i]--; }		
	}
	
	vector<ll> v;
	ROF(i,maxx,1)
	 while( cnt[i] >= 2 )
	  { v.pb(i); cnt[i] -= 2; }
	
	ll num = v.size(), ans = 0;
	for( ll i = 1; i < num; i += 2 )
	 ans += v[i]*v[i-1];
	
	cout << ans;
	  
}
