#include <bits/stdc++.h>
#include <cstdio>
#define ll long long
#define get(a) cin >> a
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
#define PI 3.14159265
using namespace std;


struct POINT {
	double x;
	double y;
};

POINT r_point(double cx, double cy, double angle, POINT p)
{
  double s = sin(angle);
  double c = cos(angle);

  p.x -= cx;
  p.y -= cy;

  double xnew = p.x * c - p.y * s;
  double ynew = p.x * s + p.y * c;

  p.x = xnew + cx;
  p.y = ynew + cy;
  return p;
}

int main() {
	ll n; get(n);
	
	rep(n) {
	  vector<POINT> v[5];
	
	  rep(4) {
		double x, y, a, b;
		cin >> 	x >> y >> a >> b;
		POINT p; p.x = x; p.y = y;
		v[i].pb(p);
		
		double par = -90;
		FOR(j,1,4) {
			POINT q = r_point( a, b, par*PI/180, p );
			par -= 90;
		//	cout << q.x << " " << q.y << endl;
			v[i].pb(q);
		}
	
	  }
	  
	  bool flag = 1;
	  
	  FOR(x,0,5)
	   FOR(y,0,5)
	   	FOR(z,0,5)
	   	  FOR(w,0,5) {
	   	  	double x1 = v[1][y].x - v[0][x].x, y1 = v[1][y].y - v[0][x].y;
	   	  	double x2 = v[2][z].x - v[0][x].x, y2 = v[2][z].y - v[0][x].y;
	   	  	double x3 = v[3][w].x - v[0][x].x, y3 = v[3][w].y - v[0][x].y;
	   	  	
	   	  	if( x1 + x2 == x3 && y1 + y2 == y3 )
	   	  		{ cout << x + y + z << endl; flag = 0; break; }
	   	  	else if( x2 + x3 == x1 && y2 + y3 == y1 )
	   	  		{ cout << x + y + z << endl; flag = 0; break; }
	   	  	else if( x1 + x3 == x2 && y1 + y3 == y2 )
	   	  		{ cout << x + y + z << endl;  flag = 0; break; }
	   	  	 
		  }
		  
		  if( flag )
		  	cout << "-1\n";
	   	  	
	  
	}
}
