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
#define INPFILE freopen("input.in","r",stdin)
using namespace std;

ll arr[100005] = {0};

void conq( ll *A, ll low, ll mid, ll high );

void divide( ll *A, ll low, ll high ) {
    if( high - low > 0 ) {
        ll mid = high + low;
        mid /= 2;
        //cout << low << " " << mid << " " << high << endl; getch();
        divide( A, low, mid );
        divide( A, mid+1, high );
        conq( A, low, mid, high );
    }
}

void conq( ll *A, ll low, ll mid, ll high ) {
     ll farr[100000+5], larr[100000+5];
     ll fcount = 0, lcount = 0;
     
     for( ll i = low; i <= mid; i++ )
        { farr[fcount] = A[i]; fcount++; }
     farr[fcount] = LONG_MAX;
     
     
     for( ll i = mid+1; i <= high; i++ )
       {  larr[lcount] = A[i]; lcount++; }
     larr[lcount] = LONG_MAX;
     
     
     ll fi = 0, li = 0;
     for( ll i = low; i <= high; i++ ) {
       if( farr[fi] <= larr[li] )
        {  A[i] = farr[fi]; fi++; }
       else {
            A[i] = larr[li];            
  //          if( li < lcount && fi < fcount )
  //			cout << " P: " << A[i] << " = " << fi << endl;
  			arr[A[i]] += fi;
            li++;
       }
     }
}
             
int main() {
   ll t; get(t);
   
   while(t--) {
     ll n,  a[100000+5] = {0}, b[100005] = {0};
     get(n);
     memset( arr, 0, sizeof arr );
     
     for( ll i = 0; i < n; i++ )
        { get(a[i]); b[i] = a[i]; }
     divide( a, 0, n-1 );
     
     for( ll i = 0; i < n; i++ )
     	printf("%ld ", b[i]-arr[b[i]]);
     printf("\n");
     
   }
}
