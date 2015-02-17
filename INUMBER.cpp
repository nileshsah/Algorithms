#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define foo(a,b,c) mp( mp(a,b), c )
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

bool flag = 0;
ll n;

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

map< pair< pair<ll,ll>, ll >, string > m;

void getnum( ll d, string s, ll sum, ll mod ) {
	if( flag ) 
		return;
	
//	m[foo(d,s,mod)] = s;
	
	if( d < 0 && sum == 0 && mod == 0 )
		{ cout << s << endl; flag = 1; return; }
	
	cout << " REC: " << s << endl;
	
	FOR(i,0,9)
	 if( flag ) return;
	 else if( sum - i >= 0 && sum - i <= 9*d ) {
	 	string temp = s; temp.pb( char(i+'0') );
	 	ll num = (mod+i*modpow(10,d,n))%n;
	 	
//	 	if( m.find(foo(d-1,sum-i,
	   getnum( d-1, temp, sum-i,  num );
	}
}

int main() {
	ll t; get(t);
	while(t--) {
		get(n); flag = 0;
		FOR(i, n/9 + 1 - ( n%9 == 0 ), 118 )
			getnum( i-1, "", n, 0 );
	}
}
