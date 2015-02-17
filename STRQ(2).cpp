#include <bits/stdc++.h>
#define ll int
#define get(a) scanf("%ld", &a);
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


ll v[1000005] = {0}, idx = 0;
long long sum[1000005][4][4] = {0};

inline ll fetch(char x );

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

inline void writeInt (int n)
    {
        int N = n, rev, count = 0;
        rev = N;
        if (N == 0) { pc('0'); return ;}
        while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
        rev = 0;
        while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
        while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
        while (count--) pc('0');
    }


void ip()
{
 //   string i="";
    int temp=gc();
    while(temp<'a'||temp>'z')
        temp=gc();
    while(temp>='a'&&temp<='z')
    {
        v[++idx] = fetch( (char)temp );
        sum[idx][v[idx]][v[idx]]++;
        FOR(i,0,3)
         FOR(j,0,3)
         sum[idx][i][j] += sum[idx-1][i][j];
        FOR(i,0,3)
         if( i != v[idx] )
          sum[idx][i][v[idx]] += sum[idx-1][i][i];
    
        temp=gc();
    }
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
	
	ll q; geti(q);
	while(q--) {
		char a, b; ll x, y;
//		scanf(" %c %c", &a, &b);
		a = gc(); gc(); b = gc();
		geti(x); geti(y);
//		cout << " - > " << a << " " << b << " " << x << " " << y << endl;
		ll aa = fetch(a); ll bb = fetch(b);
		long long ans = sum[y][aa][bb] - sum[x-1][aa][bb];
		ans -= ( sum[y][bb][bb] - sum[x-1][bb][bb] )*sum[x-1][aa][aa] ;
		printf("%lld\n", ans);
//		writeInt(ans); pc('\n');
	}
	
	
	
}
