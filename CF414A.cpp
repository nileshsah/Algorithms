#include <bits/stdc++.h>
#define ll long long
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

vector<ll> prime;

ll sieve( ll N ) {
	bool mark[2000005] = {0};
	ll n = 1299763;
	FOR(i,2,n)
	 if( !mark[i] ) {
	  for( ll k = i*i; k <= n; k += i )
	    mark[k] = 1;
	  prime.pb(i);
	  if( prime.size() > N+2 )
	    { break; }
	}
}

int main() {

	ios_base::sync_with_stdio(false);

	ll n, k;
	cin >> n >> k;
	sieve(n);
	
	ll  p = n/2;
	
	if( n == 1 && k == 0 )
	 { cout << "1"; return 0; }
	if( k - ( p - 1 ) <= 0 || p == 0 )
	  { cout << "-1"; return 0; }
	
	ll q = k - p + 1;
	ll j = 0;
	
	cout << q << " " << 2*q << " ";
	
	FOR(i,3,n) {
	 while( prime[j] == q || prime[j] == 2*q )
	  j++;
	 cout << prime[j++] << " ";
	}
	  
	
	
}
