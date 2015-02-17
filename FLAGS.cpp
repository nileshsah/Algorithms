#include<stdio.h>
#include <iostream>
using namespace std;



int main() {
    int t;
    scanf("%d", &t);
    
    while(t--) {
     int n;
     scanf("%d", &n);
     long long int count = 0, temp, temp2;
     
    if( n < 100 )  {
      count = 2*n*(n-1)*(n-1);    
      count +=  ( n*(n-1)*(n-2) > 0 ) ? n*(n-1)*(n-2) : 0 ; //cout <<  n*(n-1)*(n-2) << endl;
      count +=  ( n*(n-2)*(n-2)*(n-1) > 0 ) ? n*(n-2)*(n-2)*(n-1) : 0; //cout <<  n*(n-2)*(n-2)*(n-1) << endl;
      count +=  ( n*(n-1)*(n-2)*(n-2) > 0 ) ? n*(n-1)*(n-2)*(n-2) : 0; //cout << n*(n-1)*(n-2)*(n-2) << endl;
      cout << count << endl;
     }
     else {    
       temp = n*(n-1); //cout << temp << endl;
       temp2 = 2*n*n -5*n + 4; //cout << temp2 << endl <<"----";
       cout << temp*temp2 << endl;
     }
     /*count +=  ( n*(n-1)*(n-2) > 0 ) ? n*(n-1)*(n-2) : 0 ; cout <<  n*(n-1)*(n-2) << endl;
     count +=  ( n*(n-2)*(n-2)*(n-1) > 0 ) ? n*(n-2)*(n-2)*(n-1) : 0; cout <<  n*(n-2)*(n-2)*(n-1) << endl;
     count +=  ( n*(n-1)*(n-2)*(n-2) > 0 ) ? n*(n-1)*(n-2)*(n-2) : 0; cout << n*(n-1)*(n-2)*(n-2) << endl;
    */
    }
}

