#include <iostream>
#include <vector>
#include <map>
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
#define max(a,b) a > b ? a : b
using namespace std;

	
int main() {
	ll t;
	get(t);
	while(t--) {
		ll n;
		get(n);
		map<ll,ll> v;
			
		rep(n) {
			ll x; get(x);
			v[x]++;
		}
		
		ll num = n/2;
		num++;
		bool flag = 0;
		
		for( map<ll,ll>::iterator it = v.begin(); it != v.end(); it++ )
			if( it->second >= num )
				{ flag = 1; printf("YES %ld\n", it->first); break; }
		
		if(!flag) {
			printf("NO\n");
		}
						
	}
}
