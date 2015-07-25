#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
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

ll c[2005][2005] = {0};

int main() {
	cin.sync_with_stdio(false);
	ll n;
	cin >> n;
	ll ltor[10005] = {0};
	ll rtol[10005] = {0};
	
	FOR(i,1,n)
	 FOR(j,1,n) {
	  cin >> c[i][j];
	  ltor[n+j-i] += c[i][j];
	  rtol[i+j] += c[i][j];
	 }
	
	pair<ll,pair<ll,ll> > odd = mp(0,mp(0,0)), even = mp(0,mp(0,0));
	
	FOR(i,1,n)
	 FOR(j,1,n)
	  if( (i+j)&1 )
	   odd = max( odd, mp( ltor[n+j-i] + rtol[i+j] - c[i][j], mp(i,j) ) );
	  else
	   even = max( even, mp( ltor[n+j-i] + rtol[i+j] - c[i][j], mp(i,j) ) );
	
	
	cout << odd.F + even.F << endl;
	cout << odd.S.F << " " << odd.S.S << " "
	     << even.S.F << " " << even.S.S;
	  
	
	  
}
