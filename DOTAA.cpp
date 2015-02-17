#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <cstring>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define pb push_back
using namespace std;

int main() {
	long t;
	get(t);
	
	while(t--) {
		long n, m, d;
		vector<long> v;
		long dd = 0;
		get(n); get(m); get(d);
		
		rep(n) {
			ll x;
			get(x);
			v.pb(x);
			
			dd += x/d;
			
			if( x%d == 0 )
				dd -= 1;
		}
		
		if( dd >= m )
			printf("YES\n");
		else
			printf("NO\n");
		
	}
}
