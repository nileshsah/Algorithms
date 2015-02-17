#include <bits/stdc++.h>
#include <cstdio>
#define ll int
#define get(a) scanf("%d", &a)
#define rep(n) for( int i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define repSet(s) for( set<ll>::iterator it = s.begin(); it != s.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define max(a,b) ( (a > b) ? a : b )
#define absol(a) a >= 0 ? a : -a
#define FOR(i,a,b) for( ll i = a; i < b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000009
#define dist(a,b,x,y) ( (a-x)*(a-x) + (b-y)*(b-y) )
#define INF LONG_MAX
#define EPS 10E-3
using namespace std;

struct node {
	ll x;
	ll y;
};

int main() {
	ll n;
	node v[2000+5];
	int find = 1;
	get(n);
	
	rep(n) {
		get(v[i].x); get(v[i].y);		
	}
	
	if( n == 0 )
	{ printf("%d", 4-n); return 0; }
	
	FOR(i,0,n) {
		set< pair<ll,ll> > t;
	 FOR(j,i+1,n) {	 	
	 	pair<ll,ll> p;
		 p.first = v[j].x - v[i].x;
		 p.second = v[j].y - v[i].y;
		 t.insert(p);
  	 }
  	 
  	 for( set< pair<ll,ll> >::iterator it = t.begin(); it != t.end(); it++ ) {	 	 
		 pair<ll,ll> p1, vec, p2;
		 vec = *it;
		 p1.first = -vec.second; p1.second = vec.first;
		 p2.first = vec.second; p2.second = -vec.first;
		 
		 if( p1 == vec )
		 	continue;
		
		 find = max( find, 2 );
	 	 
	 	 	
		 if( t.count( p1 ) ) {
			find = 3;
			pair<ll,ll> sq;
			sq.first = vec.first + p1.first; sq.second = vec.second + p1.second;
		
			if( t.count(sq) )
			 { find = 4; goto bye; }
		}
		else if( t.count(make_pair(vec.first + p1.first,vec.second + p1.second) ) )
	 	 	find = 3;
	 	else if( t.count(make_pair(vec.first + p2.first,vec.second + p2.second) ) )
	 	 	find = 3;
		else {
			p1 = p2; 
			 if( t.count( p1 ) ) {
				find = 3;
				pair<ll,ll> sq;
				sq.first = vec.first + p1.first; sq.second = vec.second + p1.second;
		
				if( t.count(sq) )
				 { find = 4; goto bye; }
			}
     	}
    
	 	 
	 	 
     	
	 }
   }
   
   
   bye:
	  printf("%d", 4-find );

}
