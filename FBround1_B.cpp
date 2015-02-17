#include <bits/stdc++.h>
#define ll long long
#define get(a) scanf("%lld", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define pb push_back
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

struct trie {
	ll check;
	trie* arr[28];
}*root;

ll ans = 0;

trie *newnode() {
	trie *ptr = new trie;
	ptr->check = 1;
	
	FOR(i,0,27)
	 ptr->arr[i] = NULL;
	
	return ptr;
}

void push( string s ) {
	
	if( s.empty() )
	 return;
	 
	trie *ptr = root;
	
	FOR(i,0,s.size()-1) {
		int c = s[i] - 'a';
		if( ptr->arr[c] == NULL )
		  ptr->arr[c] = newnode();
		else
		 ptr->arr[c]->check++;
		ptr = ptr->arr[c];
	}
}

ll fetch( string s ) {
	
	if( s.empty() )
		return 0;
		
	trie *ptr = root;
	ll val = 0;
	
	FOR(i,0,s.size()-1) {
		val++;
		int c = s[i] - 'a';
		if( ptr->arr[c]->check == 1 )
		  break;
		ptr = ptr->arr[c];
	}
	
	return val;
}

void solve( string s, ll n, trie* ptr, bool flag = 0) {
	if( n >= s.size() )
		return;
	
	if( !flag  )
		ans++;
		
	if( ptr == NULL ) {
		ptr = new trie;
		
		FOR(i,0,27)
		 ptr->arr[i] = NULL;
		ptr->check = 1;
		flag = 1;
	}
   
   if( n+1 < s.size() )	
	return solve( s, n+1, ptr->arr[ s[n+1] - 'a' ], flag );
	
}

int main() {
	INPFILE;
	ll t, w = 1; get(t);
	while(t--) {
		ll n; cin >> n;
		ll ans = 0;
		string s;
		
		root = new trie;
		
		FOR(i,0,27)
		 root->arr[i] = NULL;
		
		
		FOR(i,1,n) {
			cin >> s;
			
			push(s);
			ans += fetch(s);
//			cout << " M: " << ans << endl;
		}
		
		delete root;
		
		printf("Case #%lld: %lld\n", w++, ans );
	}
}
