#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

struct node {
	string a, b;
	ll x, y;
};

int main() {
	ll t; get(t);
	while(t--) {
		set<string> s;
		vector<node> v;
		
		rep(16) {
			node p;
			cin >> p.a >> p.b;
			get(p.x); get(p.y);
			s.insert(p.a); s.insert(p.b);
			v.pb(p);
		}
		
		rep(v.size()) {
			node p = v[i];
			if( p.x > p.y )
				s.erase(p.b);
			else
				s.erase(p.a);
		}
		
		cout << *s.begin() << endl;
		
	}
}

