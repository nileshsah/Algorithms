#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

bool prime[1000005] = {0};

void sieve() {
  ll n = 1000000;
  FOR(i,2,n)
   if( !prime[i] )
    for( ll k = i*i; k <= n; k +=  i )
      prime[k] = 1;

}

int main() {
	ll x;
	cin >> x;
	sieve();
	
	FOR(i,4,x/2)
	 if( !prime[i] || !prime[x-i] ) 
	  continue;
	  else
	  { cout << i << " " << abs(x-i); return 0; }
	  
}
