#include <bits/stdc++.h>
#define ll int
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define DEBUG(x) cout << "[DEBUG]" << #x << " " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

ll arr[2005][2005] = {0};
ll ltor[2005][2005] = {0};
ll rtol[2005][2005] = {0};

int main() {
	INPFILE;
	ll n; cin >> n;
	
	FOR(i,1,n)
	 FOR(j,1,n)
	  cin >> arr[i][j];
	
	FOR(i,1,n) {
	  ll k = i, j = 1;
	  ll p = 1, q = i;
	  while( k <= n ) {
	  	ltor[k][j] = ltor[k-1][j-1] + arr[k][j];
	  	ltor[p][q] = ltor[p-1][q-1] + arr[p][q];
	  	k++; j++; p++; q++;
	  }
	  
	}
	
	FOR(i,1,n){
	  ll k = i, j = 1;
	  ll p = n, q = n-i+1;
	  while( k > 0 ) {
	  	rtol[k][j] = rtol[k+1][j-1] + arr[k][j];
	  	rtol[p][q] = rtol[p+1][q-1] + arr[p][q];
	  	k--; j++; p--; q++;
	  }
	}
	
	FOR(i,1,n) {
	 FOR(j,1,n)
	  cout << rtol[i][j] << " ";
	 cout << endl;
    }
    
    cout << "\n\n";
    FOR(i,1,n) {
	 FOR(j,1,n)
	  cout << ltor[i][j] << " ";
	 cout << endl;
    }
    
    while( 
	vector< pair<ll,pair<ll,ll> > > val;
	
	FOR(i,1,n)
	 FOR(j,1,n) {
	 	ll diff = abs(i-j);
	 	ll mix = min(i,j);
	 	ll x = ltor[i+diff][j+diff];
	 	ll y = rtol[i-mix][j+mix];
	 	val.pb( mp( x+y-arr[i][j], mp(i,j) ) );
	 }
	  
	
	sort( all(val), greater< pair<ll,pair<ll,ll> > >() );
	
	cout << val[0].F << " " << val[1].F << endl;
	cout << val[0].S.F << " " << val[0].S.S << " " 
	     << val[1].S.F << " " << val[1].S.S;
	
	  
	  
}
