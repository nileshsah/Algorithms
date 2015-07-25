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

vector<ll> sum;

ll search( ll start, ll end, ll idx ) {
	ll mid = start + end;
	mid /= 2;
	
	if( sum[mid] == idx && start >= end )
		return mid;
	else if( sum[mid] > idx )
		return search( start, mid-1, idx );
	else if( sum[mid] <= idx )
		return search( mid+1, end, idx );
}

int main() {
	ll n; cin >> n;
	ll last = 0;

	FOR(i,1,n) { 
	 ll x; cin >> x; 
	 sum.pb(x+last);
	 last += x;
	}
	
	if( sum.back()%3 )
	 { cout << "0"; return 0; }
	ll x = sum.back()/3;
	vector<ll> v1, v2;
	
	for( ll i = 0; i < sum.size()-1; i++ ) {
	  if( sum[i] == x )
		v1.pb(i);
	  if( sum[i] == 2*x )
	    v2.pb(i);
	}
	
	ll ans=  0, j = 0;
	
	 
	  for( ll i = 0; i < v1.size(); i++ )
	   for( ; j < v2.size(); j++ )
	    if( v2[j] > v1[i] )
	      { ans += v2.size() - j; break; }

	
	
	cout << ans;
	
	
}
