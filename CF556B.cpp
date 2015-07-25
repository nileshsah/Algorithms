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

int main() {
	ll n; cin >> n;
	ll arr[5000] = {0};
	ll mark[5000] = {0};
	
	FOR(i,1,n) {
	  cin >> arr[i];
	  mark[i] = i-1;
	}
	
	set<ll> s;
	
	FOR(i,1,n)
	 if(i%2) 
	 	s.insert( ( mark[i] - arr[i] + n)%n );
	 else 
	   s.insert( ( arr[i] - mark[i] + n )%n );
	
	if( s.size() == 1 )
	 cout << "Yes";
	else
	 cout << "No";
}
