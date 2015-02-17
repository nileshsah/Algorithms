#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    long long int t;
    scanf("%lld", &t);
    
    while(t--) {
     char str[100005]; long long int n, count = 0, ans;
     cin >> n;
     cin.ignore();
     cin.getline( str, 100005 );
     
     for( long int i = 0; i < n; i++ ) 
          if( str[i] == '1' )
              count++;
     
     ans = ( count*( count +1) )/2;
     cout << ans << endl;
    }
}   
     
     
    
