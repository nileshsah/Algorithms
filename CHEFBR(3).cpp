#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define llu long long unsigned
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
#define repSTL(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
using namespace std;
 
ll modPow(llu a, ll x, ll p) {
    //calculates a^x mod p in logarithmic time.
    if( x == 1 )
    	return a%p;
    llu res = 1;
    while(x > 0) {
        if( x % 2 != 0) {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        x /= 2;
    }
    return res;
}

llu num[1000] = {0};
ll mcount = 0;
map< ll,ll > dp;

ll rec( llu v, ll start, ll n ) {
	ll sum = 0;
	
	if( dp[v] != 0 )
		return dp[v];
	
	FOR(i,start,n)
		if( v&( (long long)pow(2,i) ) )  {
			llu tmp = v&num[i];
			sum++; sum += rec( tmp, i+1, n );
			sum %= MOD;
		}

	dp[v] = sum;
	return sum;		
}

 
int main() {
	
	ll n; get(n);
	vector<ll> v;
	set<ll> s;
	
	rep(n) { ll x; get(x); v.pb(x); s.insert(abs(x)); }
	
	vector< pair<ll,ll> > q;
	
	repSet(s)
		FOR(i,0,v.size()-1)
			if( v[i] == -(*it) )
				FOR(j,i+1,v.size()-1)
					if( v[j] == *it )
						q.pb( mp(i,j) );
	
	if( q.empty() )
	  { cout << "1"; return 0; }
	
	sort( all(q) );
	
	
	for( ll j = q.size()-1; j >= 0; j-- )
	 FOR(i,j+1,q.size()-1)
		if( !(q[i].F >= q[j].F && q[i].F < q[j].S && q[i].S >= q[j].S ) )
			num[j] += pow(2,i);
	
	ll ans = q.size() + 1;
	
	FOR(i,0,q.size()-1)
	 { rec( num[i], i+1, q.size()-1);  ans += dp[num[i]]; ans %= MOD; }
	 		
	printf("%lld", ans);
		
		
} 
