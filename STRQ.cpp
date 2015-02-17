#include <bits/stdc++.h>
#define ll int
#define get(a) scanf("%d", &a);
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for( typeof(v.begin()) it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( typeof(s.begin()) it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
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
#define gc getchar
#define pc(x) putchar(x);
using namespace std;

ll v[1000005] = {0};
ll idx = 1;

inline ll fetch(char);

inline void geti(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

void ip()
{
 //   string i="";
    int temp=gc();
    while(temp<'a'||temp>'z')
        temp=gc();
    while(temp>='a'&&temp<='z')
    {
        v[idx++] = fetch( (char)temp );
        temp=gc();
    }
}

inline void writeInt (int n)
    {
        int N = n, rev, count = 0;
        rev = N;
        if (N == 0) { pc('0');  return ;}
        while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
        rev = 0;
        while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
        while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
        while (count--) pc('0');
    }

struct node {
	ll arr[4][4];
	bool mark[4][4];
	ll l, r;
};

node tree[2*(2000005)];

void print( node ptr ) {
	printf("  [ %lld %lld ]\n", ptr.l, ptr.r );
	FOR(i,0,3) {
	 FOR(j,0,3)
	  cout << ptr.arr[i][j];
	 cout << endl;
	}
	cout << "\n";
}

void construct( ll x, ll y, ll a, ll b, ll r = 1 ) {
	
	if( tree[r].mark[a][b] )
		return;
		
	node &ptr = tree[r];
	ptr.l = x; ptr.r = y;
	ptr.arr[0][0] = 0;
	
	if( x == y ) {
		ptr.arr[v[x]][v[x]]++;
	}
	else {
		ll mid = ( x + y )/2;
		construct( x, mid, L );
		construct( mid+1, y, R );
		
		FOR(i,0,3)
		 FOR(j,0,3)
		  if( i == j )
		   ptr.arr[i][j] = tree[R].arr[i][i] + tree[L].arr[j][j];
		 else {
		  ptr.arr[i][j] = tree[L].arr[i][i]*tree[R].arr[j][j];
		  ptr.arr[i][j] += tree[L].arr[i][j] + tree[R].arr[i][j];
		 }
	}
	
//	cout << " R: " << r; print(ptr);
}

node query( ll x, ll y, ll r = 1 ) {
	
	ll mid = ( tree[r].l + tree[r].r )/2;
	
	if( tree[r].l >= x && tree[r].r <= y )
		return tree[r];
	if( y <= mid )
		return query( x, y, L );
	if( x > mid )
		return query( x, y, R );
	
	node qr = query( x, y, R );
	node ql = query( x, y, L );
	node ptr;
	
	FOR(i,0,3)
	 FOR(j,0,3)
	  if( i == j )
	   ptr.arr[i][j] = qr.arr[i][i] + ql.arr[j][j];
	 else {
	  ptr.arr[i][j] = ql.arr[i][i]*qr.arr[j][j];
	  ptr.arr[i][j] += ql.arr[i][j] + qr.arr[i][j];
	 }

	return ptr;
}

inline ll fetch(char x ) {
  ll num = -1;
  
  if( x == 'c' )
  	num = 0;
  else if( x == 'h' )
  	num = 1;
  else if( x == 'e' )
  	num = 2;
  else if( x == 'f' )
  	num = 3;
  return num;
}

int main() {
//	INPFILE;
	ip();
	
	construct( 1, idx-1 );
	
	ll q; geti(q);
	while(q--) {
		char a, b; ll x, y;
//		scanf(" %c %c", &a, &b);
		a = gc(); gc(); b = gc();
		geti(x); geti(y);
//		cout << " - > " << a << " " << b << " " << x << " " << y << endl;
		node ptr = query( x, y );
		writeInt(ptr.arr[fetch(a)][fetch(b)]); pc('\n');
	}
	
	
	
}
