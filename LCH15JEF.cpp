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
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

ll modpow(ll base,ll exp, ll MOD){
	ll ans=1;
	while(exp){
		if(exp%2) ans=ans*base%MOD;
		base=base*base%MOD;
		exp/=2;
	}
	if(ans<0) ans+=MOD;
	return ans;
}

int main() {
//	INPFILE;
	ll t; get(t);
	while(t--) {
		string s;
		ll m; get(m);
		cin >> s;
		
		stack<ll> idx;
		
		FOR(i,0,s.size()-1)
		 if( s[i] == '*' && s[i+1] == '*') {
		 	ll op = idx.top();
		 	idx.pop();
		 
		 	ll val = 0; i = i+2;
		
		   while( isdigit( s[i] ) )
		   	{ val *= 10; val += s[i] - '0'; i++; }
		    
		 	val = modpow( op%m, val, m );
		 	idx.push(val);
		 	i--;
		 }
		 else if( isdigit( s[i] ) ) {
		 	ll val = 0;
		   while( isdigit( s[i] ) )
		   	{ val *= 10; val += s[i] - '0'; i++; }
		    idx.push(val); i--;
		 }
		  
		  ll ans = 1;
		 while( !idx.empty() )
		  {// cout << " A: " << idx.top() << endl; 
		  ans *= idx.top(); ans %= m; idx.pop(); }
		  
	   printf("%lld\n", ans );
	}
}
