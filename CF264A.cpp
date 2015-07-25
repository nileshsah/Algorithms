#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a);
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

queue<ll> q;
string s;

ll rec( ll x ) {
   if( s[x] == 'l' ) {
	  rec( x+1 );
	  q.push(x);
    }
    else if( s[x] == 'r' ) {
    	q.push(x);
    	rec( x + 1 );
	}
}

int main() {
	cin >> s;
	s = " " + s + " ";
	rec(1);
	while(!q.empty())
	 { cout << q.front() << "\n"; q.pop(); }
}
