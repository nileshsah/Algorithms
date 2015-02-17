#include <bits/stdc++.h>
#define ll int
//#define get(a) scanf("%ld", &a)
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

struct node {
	ll num[3];
	ll l,r;
	ll lazy;
}tree[3*(100005)];

inline void get(int &a)
{
	register int c;
	a = 0;
	do c = getchar_unlocked(); while (c < '0');
	do{
		a = (a << 1) + (a << 3) + c - '0';
		c = getchar_unlocked();
	} while (c >= '0');
}

inline void printint(int a)
{
	char s[11];
	int t = -1;
 
	do{
		s[++t] = a % 10 + '0';
		a /= 10;
	} while (a > 0);
 
	while (t >= 0)putchar_unlocked(s[t--]);
	putchar_unlocked('\n');
}

void display( ll r ) {
	node ptr = tree[r];
	printf("  <%ld %ld> [ %ld %ld %ld ]\n", ptr.l, ptr.r, ptr.num[0], ptr.num[1], ptr.num[2] );
}

void construct( pair<ll,ll> p, ll r = 1 ) {
	node &ptr = tree[r];
	ptr.r = p.S; ptr.l = p.F; ptr.lazy = 0;
	FOR(i,0,2) ptr.num[i] = 0;
	
	if( p.F == p.S )
		{ ptr.num[0] = 1; }
	else {
		ll mid = ( p.F + p.S )/2;
		construct( mp(p.F,mid), L );
		construct( mp(mid+1,p.S), R );
		
		FOR(i,0,2) ptr.num[i] = tree[L].num[i] + tree[R].num[i];
	}
}

void lazyme( ll r ) {
	if( tree[r].lazy != 0 ) {
		node &ptr = tree[r];
		ll k = ptr.lazy;
		
		k %= 3;
		
		ll backup[3] = {0};
	 	FOR(i,0,2) backup[i] = ptr.num[i];
	 	FOR(i,0,2) ptr.num[i] = backup[(i-k+6)%3];
	 	
//	 	cout << "LAZY: " << k << " R: " << r; display(r);
	 	ptr.lazy = 0;
	 	
		if( ptr.r != ptr.l ) {
		 tree[L].lazy += k;
	 	 tree[R].lazy += k;
	 	}
	}
}

void update( ll x, ll y, ll r = 1 ) {
	 node &ptr = tree[r];
	 
	 lazyme(r);
	 
	 if( ptr.l > y || ptr.r < x )
	 	return;

	 	 
	 if( ptr.l >= x && ptr.r <= y ) {
	 	ll backup[3] = {0};
	 	FOR(i,0,2) backup[i] = ptr.num[i];
	 	FOR(i,0,2) ptr.num[i] = backup[(i+2)%3];
	 	tree[L].lazy++;
	 	tree[R].lazy++;
	 }
	 else {
	 	update( x, y, L );
		update( x, y, R );
	 	
	 	FOR(i,0,2) ptr.num[i] = tree[L].num[i] + tree[R].num[i];
	 }
	 
//	 cout << " R: " << r; display(r);
	 	
}

node query( ll x, ll y, ll r = 1 ) {
	ll mid = ( tree[r].l + tree[r].r )/2;
	lazyme(r);
	
	if( tree[r].l >= x && tree[r].r <= y )
		return tree[r];
	if( x > mid )
		return query( x, y, R );
	if( y <= mid )
		return query( x, y, L );
	
	node qr = query( x, y, R );
	node ql = query( x, y, L );
	node ptr;
	
	FOR(i,0,2)
	 ptr.num[i] = qr.num[i] + ql.num[i];
	return ptr;
}



int main() {
//	INPFILE;
	ll n, q;
	get(n); get(q);
	construct( mp(1,n) );
	
	while(q--) {
		ll w, x, y;
		get(w); get(x); get(y);
		
		if( w == 0 )
			update(x+1,y+1);
		else if( w == 1 ) {
			printint( query(x+1,y+1).num[0] );
		}
	}
}
