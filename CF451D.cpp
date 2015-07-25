#include <bits/stdc++.h>
#define ll long long
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

int main() {
	string s; cin >> s;
	ll a[2] = {0}, b[2] = {0};
	ll even = 0, odd = 0;
	
	FOR(i,0,s.size()-1) 
	 if( s[i] == 'a' )
	  { odd += a[i%2]; even += a[(i+1)%2]; a[i%2]++;  }
	 else if( s[i] == 'b' )
	  { odd += b[i%2]; even += b[(i+1)%2]; b[i%2]++; }
		
	odd += s.size();
	cout << even << " " << odd;
}
