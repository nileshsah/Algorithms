#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <algorithm>
#include <limits.h>
#include <cstring>
#include <cmath>
#include <string>
#include <cstdio>
#define ll long long unsigned
#define get(a) scanf("%I64u", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define max(a,b) a > b ? a : b
#define pb push_back
using namespace std;
 
ll ctick = 0;
bool flag = 1;
vector<long> prime;
 
void sieve( int n ) {
     bool a[100000+5] = {0};   
     for( ll i = 2; i <= n; i++ )
       if( a[i] == 0 ) {
          prime.pb(i); 
         for( ll j = i*i; j <= n; j += i )
          {  a[j] = 1;  }
       }
      // cout << " SI: " << prime.size();      
}
 
string longDiv( string str, long div ) {
       //cout << " DIV: " << str << "/" << div;
       ll rem = 0;
       string ans;
       bool start = 0;
       
       for( int i = 0; i < str.length(); i++ ) {
            rem *= 10;
            rem += str[i] - '0';
            ll q = rem/div;
            
         if( q > 0 )
          start = 1;
          
          if( start )
           {  ans.pb(q+'0'); rem %= div; }                 
       }
       
       if( rem != 0 )
           flag = 0;
       
      // cout << " ANS: " << ans << " REM: " << rem << endl;
       //getch();
       return ans;
}
 
ll getnum( string s ) {
   ll val = 0;
   
   for( int i = 0; i < s.size(); i++ ) {
        val *= 10;
        val += s[i] - '0';
   }
   
  // cout << " RET: " << val << "\n";
   return val;
}
 
int main() {
    ll n = 7000;
    sieve(n);
 
    int t;
    scanf("%d", &t);
    
    while(t--) {
      char s[10000];
      vector<ll> solint;
      vector<string> solstr;
      ll sq = ULLONG_MAX;
      ll num = ULLONG_MAX;
      bool intnum = false;
      scanf("%s", &s);
      string str(s);
      ll tock = 0;
      ll ntock = 0;
      bool eme = false;
      
      for( int i = 0; i < prime.size() && prime[i] <= num/2; i++ ) {
       //cout << " FINDING: " << str << " OR " << num << " BY: " << prime[i] << endl;
      // ctick++;
       if( eme )
           break;
           
       flag = 1;
       if( str.size() >= 20 ) {
         while(flag) {
          tock++;   
         string temp;
         temp = longDiv( str, prime[i] );
   
         if( flag )
          { solint.pb(prime[i]);  str = temp; tock = 0; }
          
          if( tock > 170  )
            { tock = 0;  eme = true; break; }
         }       
           
        }
        else {
          intnum = true;
          bool ff = true;
          while(ff) {
               ntock++;
             if( num == ULLONG_MAX )
                 num = getnum(str);
                 
             if( num%prime[i] == 0 )
               {  solint.pb(prime[i]); num /= prime[i]; ntock = 0; }
                
             if( num%prime[i] == 0 )
                 ff = 1;
             else
                 ff = 0;
                 
             if( ntock > 510 )
            { ntock = 0;  eme = true; break; }
         
          }
        }    
      }
    
     if( intnum && num == 1 )
         cout << solint.size() << "\n";
     else
         cout << solint.size()+1 << "\n";
     
     repVector(solint) {
       printf("%llu\n", *it);
     }
     
     if( !intnum )
      printf("%s\n", str.c_str() );
     else {
       if( num != 1 )
       printf("%llu\n", num);
     }
 
      
    }
}
 
