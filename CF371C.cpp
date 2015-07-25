#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
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
#define MOD 1000000007
#define INPFILE freopen("input.in","r",stdin)
using namespace std;


ll nb, nc, ns;
ll pb, pc, ps;
ll cb = 0, cc = 0, cs = 0;
ll r;

ll search( ll start, ll end ) {
	ll mid = ( start + end )/2;
//	cout << "R: " << mid << " - " << (mid*cb-nb)*pb + (mid*cc-nc)*pc + (mid*cs-ns)*ps << "\n";
	
	if( start > end )
	  return end;
	if( max(0LL,(mid*cb-nb))*pb + max(0LL,(mid*cc-nc))*pc + max(0LL,(mid*cs-ns))*ps <= r )
	  return search( mid+1, end );
	else
	  return search( start, mid-1 );
	
}

int main() {
	string s;
	cin >> s;
	cin >> nb >> ns >> nc;
	cin >> pb >> ps >> pc;
	cin >> r;
	
	FOR(i,0,s.size()-1)
	 if( s[i] == 'B' ) cb++;
	 else if( s[i] == 'S' ) cs++;
	 else if( s[i] == 'C' ) cc++;
    
	cout << search(1,10000000000000LL);
		
}
