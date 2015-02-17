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

void EE(ll a, ll b, ll& x, ll& y)
{
    if(a%b == 0)
    {
        x=0;
        y=1;
        return;
    }
    EE(b,a%b,x,y);
    ll temp = x;
    x = y;
    y = temp - y*(a/b);
}

ll inverse(ll a, ll m)
{
    ll x,y;
    EE(a,m,x,y);
    if(x<0) x += m;
    return x;
}

int main() {
	ll t; get(t);
	while(t--) {
		ll n, m;
		get(n); get(m);
		
		ll val = modpow( m, n );
		
		ll x = ( n%2 == 0 ) ? n : (n-1);
		
		ll inv = inverse( m-1, MOD );
		ll num = modpow( m, x/2 ) - 1;
		
		if( num < 0 ) num += MOD;
		
		num = 2*(num*inv)%MOD;
		num *= modpow( m, x/2 );
		num %= MOD;
		
		
		cout << " NUM: " << num << endl;
		cout << " VAL: " << val << endl;
		
		ll ans = val - num;
		
		if( n%2 != 0 )
			ans += modpow( m, n-1 ) + modpow( m, (n-1)/2 );
		else
			ans += modpow( m, n-1 );
		
		while( ans < 0 )
		  ans += MOD;
		ans %= MOD;
		
		printf("%lld\n", ans);
		
	}
}
 
