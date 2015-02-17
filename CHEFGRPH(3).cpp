#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define MOD 1000000007
#define INPFILE freopen("input.in","r",stdin)
#define gc getchar
#define pc(x) putchar(x);
using namespace std;
 
ll n, m, k;
#define Q 100000000
ll store[Q] = {0};
 
ll modpow(ll base,ll exp){
	if( exp <= 0 )
		return 1;
	if( exp < Q && store[exp] != 0 )
		return store[exp];
		
	ll ans=1;
	while(exp){
		if(exp%2) ans=ans*base%MOD;
		base=base*base%MOD;
		exp/=2;
	}
	if( exp < Q ) store[exp] = ans;
	return ans%MOD;
}
 
vector< pair< pair<ll,ll> ,pair<ll,ll> > > v;
vector<ll> last;
ll ans = 0;

ll search( ll start, ll end, ll p ) {
	ll mid = ( start + end )/2;	
	if( start > end )
		return end;
	if( last[mid] == p )
		return mid;
	if( last[mid] >= p )
		return search( start, mid-1, p );
	else if(  last[mid] < p )
		return search( mid+1, end, p );
}
  
int main() {
//	INPFILE;
	get(n); get(m); get(k);
	
	ans += modpow(m,n);
	set<ll> s;
	
	FOR(i,1,k) {
		ll x1, m1, y1, m2;
		get(x1); get(m1); get(y1); get(m2);
		s.insert(y1);
		v.pb( mp( mp(y1,m2), mp(x1,m1) ) );
	}
	
	sort( all(v) );
	
	repSet(s)
	 last.pb(*it);
	
	ll idx = 0;
	map< pair<ll,ll>, ll > vertex;
	ll layer[5*10005] = {0};
	bool mark[5*10005] = {0};
	
	for( ll i = 0; i < k; i++ ) {
		ll val = 0, w = 0;
		
		while( last[idx] != v[i].F.F )
			idx++;
		
		if( vertex.find(v[i].S) != vertex.end() ) {
		    val += vertex[v[i].S];
//			val += w;
//			w = w*modpow(m,v[i].F.F-v[i].S.F-1);
			val %= MOD;
		}
		else {
			ll j = search( 0, idx-1, v[i].S.F-1 );
//			for( ll j = idx-1; j >= 0; j-- )
			 if( j >= 0 && v[i].S.F > last[j] )
		      { val += layer[j]*modpow(m,v[i].S.F-last[j]-1); }
//		    cout << " CHK: " << layer[j] << "*" << v[i].S.F-last[j]-1 << endl;
	    }
	    
	    val %= MOD;
	    
	    ll abc = 0;
	    
	    if( idx-1 >= 0 )
	      abc = layer[idx-1]*modpow(m,last[idx]-last[idx-1]-1);
		
		abc %= MOD;
		val += modpow(m,v[i].S.F-1);
		val %= MOD;
		
		ll rx = ( last[idx] != n+1 ) ? m : 1;
		
		layer[idx] += val;
		if( !mark[idx] )
		 layer[idx] += ( abc*rx )%MOD;
		mark[idx] = 1;
		layer[idx] %= MOD;
		vertex[v[i].F] += ( val + abc )%MOD;
		vertex[v[i].F] %= MOD;
		
//		cout << v[i].S.F << " " << v[i].S.S << " " << v[i].F.F << " " << v[i].F.S << endl;
//		cout << " I: " << i << " Layer: " << layer[idx] << " = " << vertex[v[i].F] << endl;
	}
  if( !last.empty() ) {	
	 ll i = idx;
	 ans += ( modpow(m,n-last[idx])*layer[i] )%MOD;
  }
	
	printf("%lld", ans%MOD);
	
}

		
		
	 
