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

int main() {
	ll t; cin >> t;
	while(t--) {
		ll n; cin >> n;
		ll c[100] = {0}, sum = 0;
		bool flag = 0;
		FOR(i,1,n) {
		  cin >> c[i];
		  sum += c[i];
		  if( c[i] == n )
		    flag = 1;
		}
		
		if( sum != n || flag )
		  { cout << "-1\n"; continue; }
		
		queue<ll> q;
		ROF(i,n,1)
		 FOR(j,1,c[i])
		  q.push(i);
		
		FOR(i,1,n)
		 while( q.size() != n-i )
		  if( q.front() != i ) {
		 	cout << q.front() << " ";
		 	q.pop();
		 	c[i]--;
		  }
		 else {
		   q.push(q.front());
		   q.pop();
		 }
		   
		 cout << "\n";	
		
		 
	}
}
