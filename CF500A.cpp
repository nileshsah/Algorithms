#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define max(a,b) ( (a > b) ? a : b )
#define min(a,b) ( (a < b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

ll path[30005] = {0};
bool visit[30005] = {0};

int main() {
	ll n, ptr;
	cin >> n >> ptr;
	vector<ll> v(n+1);
	
	rep(n-1) {
	 cin >> v[i];
	 path[i] = v[i] + i;
	}
	
	
	ll idx = 1;
	
	while(1) {
		if( idx == ptr )
		 { cout << "YES"; return 0; }
		if( visit[idx] || idx == 0 )
			{ cout << "NO"; return 0; }
		visit[idx] = 1;
		idx = path[idx];
		
	}
	 
	
	
	 
	 	
}
