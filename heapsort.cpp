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
#define matrix vector< vector<ll> >
#define MOD 10000007
#define F first
#define S second
#define L 2*r
#define R 2*r+1
#define mp make_pair
using namespace std;

inline void swap( int &a, int &b ) {
	int temp = a;
	a = b;
	b = temp;
}

void max_heapify( int *a, int r, int size ) {
	int max = r;
	if( L <= size && a[L] > a[max] )
		max = L;
	if( R <= size && a[R] > a[max] )
		max = R;
	if( max != r ) {
		swap( a[r], a[max] );
		max_heapify( a, max, size );
	}
}

void build_heap( int *a, int size ) {
	for( int i = size/2; i >= 1; i-- )
		max_heapify( a, i, size );
}

void heap_sort( int *a, int size ) {
	build_heap( a, size );
	for( int i = size; i >= 2; i-- ) {
		swap( a[i], a[1] );
		max_heapify( a, 1, i-1 );
	}
}

int partition( int *a, int start, int end ) {
	int pvt = a[end];
	int pIndex = start;
	
	FOR(i,start,end-1) 
		if( a[i] <= pvt ) {
			swap( a[i], a[pIndex] );
			pIndex++;
		}
	swap( a[end], a[pIndex] );
	return pIndex;
}


void Qsort( int *a, int start, int end ) {
		if( start >= end ) return;
		int pIndex = partition( a, start, end );
		
	//	cout << " Q: " << start << " " << end << " -> " << pIndex << endl;
	
		Qsort( a, start, pIndex-1 );
		Qsort( a, pIndex+1, end );
}

int main() {
	int a[100], n;
	cout << "Enter n: "; cin >> n;
	cout << "Enter elements: ";
	
	for( int i = 1; i <= n; i++ )
		cin >> a[i];
//	heap_sort( a, n );
	Qsort( a, 1, n );
	
	FOR(i,1,n)
	 cout << a[i] << " ";
}
