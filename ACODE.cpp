#include <iostream>
using namespace std;

int main() {
    char str[5000+5];
    while(1) {
     cin.getline( str, 5005 );
     if( str[0] == '0' )
         break;
     
    long long unsigned int dp[5000+5];
    dp[0] = 1;
    
    int i;
    
    for( i = 1; str[i] != '\0'; i++ ) {
         int num = str[i-1] - '0';
         num *= 10; num += str[i] - '0';
         
         dp[i] = 0;
         
         if( num <= 26 && str[i-1] != '0' )
             dp[i] += (i-2 >= 0) ? dp[i-2] : 1;
         
         if( str[i] != '0' )
             dp[i] += dp[i-1];
    }
    
    cout << dp[--i] << endl;
  }
}
         
         
         
    
