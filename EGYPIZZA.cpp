#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <limits.h>
#include <cstring>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define pb push_back
using namespace std;

int main() {
    ll t, min = LONG_MAX;
    get(t);
    cin.ignore();
    
    ll aa1 = 0, aa2 = 0, aa3 = 0;
    while(t--) {
      char c[10];
      scanf("%s", &c);
      
      if( c[0] == '1' && c[2] == '4' )
        aa1++;
      else if( c[0] == '1' && c[2] == '2' )
        aa2++;
      else if( c[0] == '3' )
        aa3++;
    }
           
      ll sum = 1;
      
      ll a1 = aa1, a2 = aa2, a3 = aa3;
     //cout << a1 << " " << a2 << " " << a3 << endl;
      ll pair = a1/2;
      
      if( pair <= a2 )
       { sum += pair; a1 -= pair*2; a2 -= pair; }
      else
       { sum += a2; a1 -= a2*2; a2 = 0; }
       
      if( a1 >= a3 )
       { sum += a3;  a1 -= a3; a3 = 0; }
      else
       { sum += a1; a3 -= a1; a1 = 0; }
      
      sum += a2/2;
      a2 %= 2;
      sum += a1/4;
      a1 %= 4;
       
      
      //cout << a1 << " " << a2 << " " << a3 << " ->" << sum << endl;
      sum += a1;
      sum += a2;
      sum += a3;
      
      min = sum;
      
      sum = 1;
      a1 = aa1, a2 = aa2, a3 = aa3;

       
      if( a1 >= a3 )
       { sum += a3;  a1 -= a3; a3 = 0; }
      else
       { sum += a1; a3 -= a1; a1 = 0; }
      
      pair = a1/2;
      
      if( pair <= a2 )
       { sum += pair; a1 -= pair*2; a2 -= pair; }
      else
       { sum += a2; a1 -= a2*2; a2 = 0; }
      
      sum += a2/2;
      a2 %= 2;
      sum += a1/4;
      a1 %= 4;
      
      sum += a2;
       a1 -= a2*2;
      if( a1 > 0 )
       sum += a1;
      sum += a3;
      
      min = min > sum ? sum : min;
      
       sum = 1;
      a1 = aa1, a2 = aa2, a3 = aa3;

      sum += a2/2;
      a2 %= 2;
      sum += a1/4;
      a1 %= 4;
      
      if( a1 >= a3 )
       { sum += a3;  a1 -= a3; a3 = 0; }
      else
       { sum += a1; a3 -= a1; a1 = 0; }
      
      pair = a1/2;
      
      if( pair <= a2 )
       { sum += pair; a1 -= pair*2; a2 -= pair; }
      else
       { sum += a2; a1 -= a2*2; a2 = 0; }
      
          
        sum += a2;
       a1 -= a2*2;
      if( a1 > 0 )
       sum += a1;
      sum += a3;
      
      min = min > sum ? sum : min;
      
      printf("%ld", min);
    
     //cin >> t;  
}
