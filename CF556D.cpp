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

vector< pair<ll,ll> > v;
vector< pair<ll,ll> > adj;

bool mark[1000000] = {0};

bool check( ll d, ll i ) {
	ll mindist = v[i+1].F - v[i].S;
	ll maxdist = v[i+1].S - v[i].F;
	
	if( d >= mindist && d <= maxdist )
	 return 1;
	return 0;	
}

ll search( ll start, ll end, ll ptr ) {
	while( mark[start] )
	 start++;
	while( mark[end] )
	 end--;
	 
	ll mid = ( start + end )/2;
	
	ll mindist = v[ptr+1].F - v[ptr].S;
	ll maxdist = v[ptr+1].S - v[ptr].F;
	
	ll d = adj[mid].F;
	
	if( start > end )
	 if( end >= 0 && check(adj[end].F,ptr) )
	  { mark[end] = 1; return end; }
	 else
	  { mark[start] = 1; return start; }

//	cout << " R: " << start << " " << end << " = " << d << "\n";
	
	if( d < mindist )
	 return search( mid+1, end, ptr );
	if( d > maxdist )
	 return search( start, mid-1, ptr );
	
	bool exp = d + v[ptr].F > v[ptr+1].F;
	exp = exp&&( v[ptr+1].S > v[ptr].S + d);
		 
	if(exp)
	 return search( start, mid-1, ptr );
	else
	 return search( mid+1, end, ptr );
}

int main() {
//	INPFILE;
	BOOST;
	ll n, m;
	cin >> n >> m;
	
	FOR(i,1,n) {
	  ll l, r;
	  cin >> l >> r;
	  v.pb( mp(l,r) );
	}
	
	FOR(i,1,m) {
	 ll x; cin >> x;
	 adj.pb( mp(x,i) );
	}
	
	sort( all(adj) );
	
	if( m < n-1 )
	 { cout << "No"; return 0; }
	
	vector<ll> ans;
	FOR(i,0,n-2) {
		ll mindist = v[i+1].F - v[i].S;
		ll maxdist = v[i+1].S - v[i].F;

		ll k = search( 0, adj.size()-1, i );
		
//		debug(adj[k].S);
		
		if( adj[k].F >= mindist && adj[k].F <= maxdist )
		  { ans.pb(adj[k].S); adj.erase(adj.begin()+k);  }
		else
		 { cout << "No"; return 0; }
	}
	
	cout << "Yes\n";
	repVector(ans)
	 cout << *it << " ";
	 
}
