#include <bits/stdc++.h>
#include <cstdio>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(list<int>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) a >= 0 ? a : -a
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define X first
#define Y second
using namespace std;

struct node {
  int x;
  int y;
  int z;
};

int main() {
	ll n, m, k;
	get(n); get(m); get(k);
	int adj[100+5][100+5] = {0};
	list<int> v1[100+5], v2[105];
	vector<node> ans;
	
	rep(k) {
		ll x, y;
		get(x); get(y);
		v1[x].pb(y);
		v2[y].pb(x);
		adj[x][y] = 1;
	}
	
	FOR(i,1,max(n,m)+1) {
		v1[i].sort();
		v2[i].sort();
	}
	
	ll count = 0;
	bool flag = false;
	
	FOR(i,1,m+1)
	 FOR(j,1,n+1 ) {
	 	if( j == 1 )
	 	 flag = false;
	 	if( adj[j][i] == 1 )
	 	 { flag = false; continue; }
	 	
	 	if( !flag ) {
	 	 node ptr;
	 	 ptr.x = j, ptr.y = i; ptr.z = 1;
	 	 ans.pb(ptr);
	 	 flag = true;
	 	}
	 	//cout << " FOR: " << i << " " << j;
	 }
		 
	 		 
	 		
	 printf("%ld\n", ans.size());
	 rep(ans.size())
	  printf("%ld %ld %ld\n", ans[i].x, ans[i].y, ans[i].z );	  
	 	
}
