#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( multiset<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

multiset<ll> v;
bool flag;

void rec( multiset<ll>::iterator it, multiset<ll> s, ll sum, ll val ) {
//	cout << " REC: " << *it << " " << sum << endl;
	if( sum == val )
	 { v = s; flag = 1; return; }
	if( flag || it == v.end() )
		return;	
	if( sum > val )
		return;
	
	ll x = *it;
	it++;
	rec( it, s, sum, val );
	sum += x;
	s.erase(s.find(x));
	rec( it, s, sum, val );	
	
}


int main() {
	ll t; get(t);
	while(t--) {
		ll n, k, sum = 0, mx = 0;
		get(n); get(k);
		v.clear();
		
		rep(n) { ll x; get(x); v.insert(x); sum += x; mx = max(mx,x); }
		
		
		if( sum%k != 0 )
			{ printf("no\n"); continue; }
		else if( mx <= sum/k ){
			ll val = sum/k, z;
			for( z = 1; z <= k; z++ ) {			
				if( v.empty() )
				 { printf("no\n"); break; }
			
				flag = 0;
				ll r = *v.rbegin();
				r = val - r;
				v.erase( v.find(*v.rbegin()) );
				
				rec( v.begin(), v, 0, r );
				
			//	cout << r << "---------\n";
				if( !flag )
				 { printf("no\n"); break; }
			}
		//	cout << " END: " << z << endl;
			if( z == k+1 )
				printf("yes\n");
		}
		else {
			printf("no\n"); continue;
		}
		
		
	}
}
