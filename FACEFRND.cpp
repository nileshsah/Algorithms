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
#define max(a,b) a > b ? a : b
using namespace std;

int main() {
	ll n;
	set<ll> v;
	vector<ll> f;
	get(n);
	
	while(n--) {
		ll m, ff;
		get(ff); get(m);
		f.pb(ff);
		
		while(m--) {
			ll x; get(x);
			v.insert(x);
		}
		
	}
	
	repVector(f)
		v.erase(*it);
	cout << v.size();
}
