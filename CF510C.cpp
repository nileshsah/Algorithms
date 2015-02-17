#include <bits/stdc++.h>
#define ll long
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
#define MOD 1000000007
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

bool mark[200] = {0};
set<ll> v[200], s;
vector<ll> adj[200], ans;
ll deg[200] = {0};

void solve() {
	
	while(!s.empty()) {
		ll top = *s.begin();
		s.erase(s.begin());
		ans.pb(top); mark[top] = 1;
		
		repVector(adj[top]) {
		  deg[*it]--;
		  if(!deg[*it])
		 	s.insert(*it);
		}
	}
}

bool cyclic( vector<ll> v[] ) {
	bool visit[1005] = {0};
	queue<int> q;
	
	FOR(i,'a','z')
		if( visit[i] == 0 ) {
			q.push(i); visit[i] = 1;
			while( !q.empty() ) {
				ll c = 0;			
				repVector(v[q.front()])
					if( !visit[*it] )
					 { q.push(*it); visit[*it] = 1; }
					else c++;
				q.pop();
				if( c > 1 ) return true;
			}		
		}
	return 0;
}


int main() {
	INPFILE;

	ll n; get(n);
	string s[105];
	
	FOR(i,0,n-1)
	  cin >> s[i];
	
	FOR(i,0,n-1)
	 FOR(j,i+1,n-1) {
	 	ll k = 0;
	   while( k < min( s[i].size(), s[j].size() ) && s[i][k] == s[j][k] ) k++;
		if( k == min( s[i].size(), s[j].size() ) ) 
		 if( s[j].size() < s[i].size() )
		  { cout <<"Impossible"; return 0; }
		 else
		  continue;
	   
	   	  v[ s[j][k] ].insert( s[i][k] );
	   }
	
	
	FOR(i,'a','z')
	 repSet(v[i]) {
	  adj[*it].pb(i);
	  deg[i]++;
	}
	
	if( cyclic( adj ) )
		{ cout << "Impossible"; return 0; }
	
	FOR(i,'a','z')
	 if(!deg[i])
	  ::s.insert(i);
	
	solve();
	FOR(i,0,ans.size()-1)
	 printf("%c", ans[i]);
	 	
	
		
}
