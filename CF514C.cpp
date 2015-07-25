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
#define ROF(i,a,b) for( ll i = a; i >= b; i-- )
#define debug(x) cout << "[DEBUG] " << #x << " = " << x << endl
#define matrix vector< vector<ll> >
#define F first
#define S second
#define mp make_pair
#define L 2*r
#define R 2*r+1
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

inline int f( char c ) {
	if( c == 'a' )
		return 1;
	else if( c == 'b' )
		return 2;
	else if( c == 'c' )
		return 3;
	else if( c == '$' )
		return 0;
}

struct trie {
	char key;
	trie *arr[4];
}root;

void insert( string s ) {
	trie *ptr = &root;
	FOR(i,0,3)
	 root.arr[i] = NULL;
	 
	s += '$';
	repVector(s) {
		if( ptr->arr[f(*it)] == NULL ) {
		  ptr->arr[f(*it)] = new trie;
		  ptr->key = *it;
		  FOR(i,0,3)
			ptr->arr[f(*it)]->arr[i] = NULL;
		}		
		ptr = ptr->arr[f(*it)];	
	}
}

bool search( string s, ll p, trie *ptr , bool flag = 0 ) {	
	if( ptr == NULL || p > s.size()  )
		return 0;
	cout << s[p] << " " << p << " F:" << flag << endl;

	if( flag && ptr->arr[0] != NULL && s[p] == '$' )
		return 1;
	else if( p == s.size() )
		return 0;
	
	bool val = 0;
	if( s[p] == ptr->key )
	 val += search( s, p+1, ptr->arr[f(s[p])], flag );
	if(!flag)
	 FOR(i,0,3)
	  if( f(s[p]) != i )
	   val += search( s, p+1, ptr->arr[i], 1 );
	
	return val;  	 
}

int main() {
	ll n, m;
	cin >> n >> m;
	
	FOR(i,1,n) {
		string x; cin >> x;
		insert(x);
	}
	
	FOR(i,1,m) {
		string x; cin >> x;
		x += '$';
		if( search( x, 0, &root ) )
		 cout << "YES\n";
		else
		 cout << "NO\n";
	}
}
