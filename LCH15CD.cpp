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
#define foo(a,b,c) mp( mp(a,b), c )
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

ll n, d;

ll dfs( ) {
	map< vector<ll>, ll > m;
	set< pair<ll,vector<ll> > > s;
	vector<ll> v(n,0);
	s.insert( mp(0,v) );
	m[v] = 0;
	
	while( !s.empty() ) {
		vector<ll> cor = s.begin()->S;
		ll val = s.begin()->F;
		s.erase(s.begin());
			
		ll xxor = 0, sum = 0;
		FOR(i,0,n-1) {
			xxor ^= cor[i];
			sum  += cor[i];
		}
		
		 val += xxor*sum;
		 	
/*		cout << " REC: ";	
		FOR(i,0,n-1)
		 cout << cor[i] << " ";
		cout << endl << " VAL: " << val << endl;
*/	
//		system("pause");
		
	//	if( cor[0] == 65535 )
	//		cout << "CATCH" << sum << endl;
		
		if( sum == n*(d-1) )
		 { return val; }
		
		FOR(i,0,n-1)
		 if( cor[i] < d-1 ) {
		 	cor[i]++;
		 	vector<ll> temp = cor;
		 	sort( all(temp) );
		 	
		 	if( m.find(temp) == m.end() )
		 	 s.insert( mp(val,temp) );
		 	else if( m.find(temp) != m.end() ) {
		 	 s.erase( mp( m[temp], temp ) );
		 	 s.insert( mp( val, temp ) );
		 	 m[temp] = val;
		 	}
		 	cor[i]--;
		 }	
			
	}
	
	 	
}


int main() {
	ll t; get(t);
	while(t--) {
		get(n); get(d);
		
		ll cor[11] = {0};
		ll ans = 0;
		
		ll ptr = 1;
		
		FOR(i,0,d-2)
		 FOR(j,1,n) {
		 	cor[j]++;
		 	ll xxor = 0, sum = 0;
		  FOR(k,1,n) {
		   xxor ^= cor[k];
		   sum += cor[k];
		  }
		   ans += xxor*sum;
		 }
		 
		 ll arr[11] = {0};
		 ll tmp = 0;
		
	  while( ptr <= n ) {
		FOR(i,0,d-2)
		 FOR(j,ptr,min(n,ptr+1)) {
		 	arr[j]++;
		  ll xxor = 0, sum = 0;
		  FOR(k,1,n) {
		   xxor ^= arr[k];
		   sum += arr[k];
		  }
/*		  		cout << " REC: ";	
			FOR(i,1,n)
			 cout << arr[i] << " ";
			cout << endl;
*/
			  	tmp += xxor*sum;
//			cout << " TMP: " << tmp << endl;
	
		 }
		 
		 ptr += 2;
	}
		   
	  printf("%lld\n", min(tmp,ans));
		
	}
}
