#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

ll modpow(ll base,ll exp,ll MOD){
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
	 char str[1005];
	 scanf("%s", &str);
	 ll idx[11] = {0};
	 
	 string s(str);
	 
	 FOR(i,0,s.size()-1)
	 	idx[ s[i] -'0' ]++;
	 
	 ll n; get(n);
	 vector<ll> B;
	 
	 FOR(i,1,n)
	  { ll x; get(x); B.pb(x); }
	  
	 ll arr[105] = {0};
	 string ans;
 
	 FOR(i,1,s.size()-idx[0]) {
	 	ll sol = 1, mix = INT_MAX;
	 
	 	FOR(j,1,9)
	 	  if( idx[j] != 0 ) {
	 	  	ll sum = 0;
		    FOR(k,0,n-1)
	 	  	 sum += ( arr[k]*modpow(10,i-1,B[k]) + j )%B[k];
	 	  	
	 	  	if( sum < mix )
	 	  	  { mix = sum; sol = j; }
		  }
			
			idx[sol]--;
		FOR(k,0,n-1)
	 	  arr[k] = ( arr[k]*modpow(10,i-1, B[k]) + sol )%B[k];
	 	ans.pb( sol +'0' );
	 }
	 	  
	 reverse( all(ans) );
	 
	 FOR(i,1,idx[0])
	 	ans = "0" + ans;
		 
	 
	 
	 cout << ans << endl; 
   }
}
