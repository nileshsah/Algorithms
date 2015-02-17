#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
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

ll modpow(ll base,ll exp){
	ll ans=1;
	while(exp){
		if(exp%2) ans=ans*base%MOD;
		base=base*base%MOD;
		exp/=2;
	}
	if(ans<0) ans+=MOD;
	return ans;
}


ll search( ll start, ll end, double q = 0 ) {
	ll mid = ( start + end )/2;
	
	ll i = mid;
	ll x = n/i;
	ll y = n - x*i;
	
	if( start >= end )	
		return start;
			
	double temp = x*log10(i);
	if( y > 0 )
		 temp += log10(y);
			
	if( temp > q )
		return search( mid+1, end, temp );
	else if( temp < q )
		return search( start, mid-1, q );
			
}

int main() {
	ll t; get(t);
	while(t--) {
		ll n; get(n);
		double q = 0;
		
		ll m = sqrt(n);
		ll ans = 0;
		
		for( ll i = n/2; i >= 1; i-- ) {
			ll x = n/i;
			ll y = n - x*i;
			
			double temp = x*log10(i);
			if( y > 0 )
			 temp += log10(y);
			
			cout << i << " " << temp << endl;
			
			ll val = (modpow( i, x )*y)%MOD;
			
			if( temp > q )
			 { ans = val; q = temp; }
			else
			  break;
		}
		
		double qq = 0;
		
		for( ll i = n/2; i <= n; i++ ) {
			ll x = n/i;
			ll y = n - x*i;
			
			double temp = x*log10(i);
			if( y > 0 )
			 temp += log10(y);
			
			cout << i << " " << temp << endl;
			
			ll val = (modpow( i, x )*y)%MOD;
			
			if( temp > qq )
			 { asns = ( temp > q) ? val : ans; qq = temp; }
			else
			  break;
		}
		
		
		cout << ans << endl;
		 
			
	}
}
