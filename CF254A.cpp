#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a);
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

ll num[5005] = {0};

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	ll n; get(n);
	vector<ll> v[5005];
	FOR(i,1,2*n)
	 { ll x; get(x); num[x]++; v[x].pb(i); }
	
	FOR(i,1,5000)
	 if( num[i]%2 )
	  { cout << "-1"; return 0; }
	
	FOR(i,1,5000) {
	  ll j = 0;
	 while(num[i]) {
	   printf("%ld %ld\n",v[i][j],v[i][j+1]);
	   num[i] -= 2;
	   j += 2;
	 }
	}
	 
}
