#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( auto it = s.begin(); it != s.end(); it++ )
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

vector<ll> v;

bool compare( ll x, ll y ) {
	ll n = v.size();
	FOR(i,0,v.size()-1)
	 if( v[(i+x)%n] > v[(i+y)%n] )
	 	return 1;
	 else if( v[(i+x)%n] > v[(i+y)%n] )
	 	return 0;
	
	 return 0;
}


long long int count = 0;
void conq( vector<ll> &v, ll low, ll mid, ll high );
map<ll,ll> inv;

void divide( vector<ll> &v, ll low, ll high ) {
    if( high - low > 0 ) {
        ll mid = high + low;
        mid /= 2;
        //cout << low << " " << mid << " " << high << endl; getch();
        divide( v, low, mid );
        divide( v, mid+1, high );
        conq( v, low, mid, high );
    }
}

void conq( vector<ll> &v, ll low, ll mid, ll high ) {
     ll fvrr[100000+5], lvrr[100000+5];
     ll fcount = 0, lcount = 0;
     
     for( ll i = low; i <= mid; i++ )
        { fvrr[fcount] = v[i]; fcount++; }
     fvrr[fcount] = LONG_MAX;
     
     for( ll i = mid+1; i <= high; i++ )
       {  lvrr[lcount] = v[i]; lcount++; }
     lvrr[lcount] = LONG_MAX;
     
     
     ll fi = 0, li = 0;
     for( ll i = low; i <= high; i++ ) {
       if( fvrr[fi] <= lvrr[li] )
        {  v[i] = fvrr[fi]; fi++; }
       else {
            v[i] = lvrr[li];            
            if( li < lcount && fi < fcount ) {
             inv[ v[i] ] = fcount - fi;
             ::count += fcount - fi;
         	}
            li++;
       }
     }
}

int main() {
	ll t; cin >> t;
	while(t--) {
		v.clear();
		inv.clear();
		set<ll> s;
		ll n; cin >> n;
		FOR(i,1,n)
		 { ll x; cin >> x; v.pb(x); s.insert(x); }
		vector<ll> w(s.size());
		copy( all(s), w.begin() );
		map<ll,ll> less, greater;
		
		FOR(i,0,w.size()-1) {
		 less[ w[i] ] = i;
		 greater[ w[i] ] = w.size() - i - 1;
		}
		
		::count = 0;
		vector<ll> q = v;
		ll p = 0;
		divide( v, 0, n-1 );	
		ll ans = ::count;
		
		ll val = ::count;
		
		FOR(i,0,n-1) {
		 val += greater[ q[i] ];
		 val -= inv[ q[i] ];
		 
		 debug(val);
		 
		 if( val > ans || ( val == ans && compare(p,i) ) )
		   { p = i; ans = val; }
		}
		  
		 
		 cout << p << " " << ans << "\n"; 
		  
				
		
				
	}
}
