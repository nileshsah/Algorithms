#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define get(a) scanf("%lld", &a)
#define rep(n) for( ll i = 1; i <= n; i++ )
#define repVector(v)  for(vector< pair<ll,ll> >::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set< pair< ll, pair<ll,ll> > >::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i <= n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) ( ( a >= 0 ) ? a : -a )
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<double> >
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;


int main() {
	ll a,b,x,y;
	cin >> a >> b >> x >> y ;
	
	ll p1 = a*b, p2 = x*y;
	
	ll f2 = 0, f3 = 0;
	ll s2 = 0, s3 = 0;
	
	while( p1%2 == 0 )
		{ f2++; p1 /= 2; }
	while( p2%2 == 0 )
	 { s2++; p2 /= 2; }
	while( p1%3 == 0 )
	 { f3++; p1 /= 3; }
	while( p2%3 == 0 )
	 { s3++; p2 /= 3; }
	 
	 if( p1 != p2 )
	  { cout << "-1"; return 0; }
	
	ll step = 0;
	
	ll t2, t3, y2, y3;
	if( f3 > s3 )
	 { t2 = s2; t3 = s3; y2 = f2; y3 = f3; }
	else
	 { t2 = f2; t3 = s3; y2 = s2; y3 = s3; }
	
	step += y3 - t3;
	y2 += step;
	t3 = min( t3, y3 );
	
	step += abs( y2 - t2 );
	t2 = min( t2, y2 );
	
	cout << step << endl;
	
	ll mul = pow(2,t2)*pow(3,t3)*p1;
	
	ll dif = f3 - t3;
	
	while( a%3 == 0 && dif > 0 )
		{ a /= 3; a *= 2; dif--; }
	while( b%3 == 0 && dif > 0 )
		{ b /= 3; a *= 2; dif--; }
	
	 dif = f2 - t2;
	
	while( a%2 == 0 && dif > 0 )
		{ a /= 2; dif--; }
	while( b%2 == 0 && dif > 0 )
		{ b /= 2; dif--; }
	cout << a << " " << b << endl;
	
	
	a = x; b = y;
	
	dif = s3 - t3;
	
	while( a%3 == 0 && dif > 0 )
		{ a /= 3; a *= 2; dif--; }
	while( b%3 == 0 && dif > 0 )
		{ b /= 3; a *= 2; dif--; }
	
	dif = s2 - t2;
	
	while( a%2 == 0 && dif > 0 )
		{ a /= 2; dif--; }
	while( b%2 == 0 && dif > 0 )
		{ b /= 2; dif--; }
	cout << a << " " << b ;
	
	
	
	
		

	

	
}
