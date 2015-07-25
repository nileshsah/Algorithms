#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
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
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

vector<ll> v;
ll n, m;

bool check( ll t ) {
	vector<ll> r = v;
	if(r.empty())
	 return 1;
	 
	FOR(i,1,m) {
	   ll time = t;
	   time -= r.size();
	   while(time) {
	   	  ll x = min(time,r.back());
	   	  time -= x;
	   	  r[r.size()-1] -= x;
	   	  while(!r.back())
	   	   r.pop_back();
	   	  if(r.empty())
	   	   return 1;
	   }
	}
	return 0;
}

ll search( ll start, ll end ) {
	ll mid = ( start + end )/2;
	
	if( start > end )
	 return start;
	if( check(mid) )
	 return search( start, mid-1 );
	else
	 return search( mid+1, end );
}

int main() {
	cin >> n >> m;
	FOR(i,1,n)
	 { ll x; cin >> x; v.pb(x); }
	
	while(!v.back())
	 v.pop_back();
	 
	cout << search(0,LLONG_MAX);
}
