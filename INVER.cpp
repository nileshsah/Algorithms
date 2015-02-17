#include <iostream>
#include <limits.h>
//#include <conio.h>
#define ll long 
using namespace std;

long long int count = 0;
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
            if( li < lcount && fi < fcount )
             ::count += fcount - fi;
            li++;
       }
     }
}
             
int main() {
   ll t;
   cin >> t;
   
   while(t--) {
     ll n,  a[200000+5] = {0};
     cin >> n;
     
     for( ll i = 0; i < n; i++ )
          cin >> a[i];
     ::count = 0;
     divide( a, 0, n-1 );
     
      /* for( ll i = 0; i < n; i++ )
         cout << a[i] << "  "; */
     cout << ::count << endl;
   }
}
