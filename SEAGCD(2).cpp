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

ll modPow(ll base,ll exp){
	if( base == 1 )
		return 1;
	ll ans=1;
	while(exp){
		if(exp%2) ans=(ll)ans*base%MOD;
		base=(ll)base*base%MOD;
		exp/=2;
	}
	if(ans<0) ans+=MOD;
	return ans;
}

int main() {
	ll t; get(t);
	while(t--) {
		ll n, m, l, r;
		get(n); get(m); get(l); get(r);
	
		
		vector<ll> A(m+1,0), B(m+1,0);
		
		ll last = -1;
		
		FOR(i,l,m) {
		  if( m/i == last )
		   { A[i] = A[i-1]; }
		  else {
			  A[i] = modPow( m/i, n );
			  last = m/i;
		  }
		  cout << A[i] << " ";
		}
		
		cout << endl;
		
		ll sum = 0;
		
		for( ll i = m; i >= l; i-- ) {
			B[i] = A[i];
		  for( ll j = 2; j*i <= m; j++ )
		  	B[i] -= B[j*i];
		   
		   while( B[i] < 0 )
		   	B[i] += MOD;
		  cout << B[i] << " ";
		}
		
		FOR(i,l,r)
		 { sum += B[i]; sum %= MOD; }
		
		printf("%lld\n", sum);
		
	}
}
