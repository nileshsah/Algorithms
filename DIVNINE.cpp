#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define repVector(v)  for( auto it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( auto it = s.begin(); it != s.end(); it++ )
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
	ll t; get(t);
	while(t--) {
		string s;
		cin >> s;
		ll len = s.size()-1;
		ll sum = 0, inc = 0, dec = 0;
		
		FOR(i,0,len) {
		 sum += s[i] - '0';
		 inc += 9 - ( s[i] - '0' );
		 dec += s[i] - '0';
		}
		
		if( s.size() > 1 )
		 dec -= s[0] - '0';
		
		ll num = sum/9;
		ll x = 9*num, y = 9*(num+1);
		ll op1 = LONG_MAX, op2 = LONG_MAX;
		
		if( sum - x <= dec )
		 op1 = sum - x;
		
		if( y - sum <= inc )
		 op2 = y - sum;
		 
		cout << min( op1, op2 ) << "\n";
		
		
	}
}


