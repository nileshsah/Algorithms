#include <stdio.h>
#include <math.h>

long long int dp[1562501];  

long long int comb( int n ) {
     if( dp[n] != 0 || n == 1)
         return dp[n];
     
     if( dp[n-1] == 0 )
         comb(n-1);
     
     long long int c = 0;
     double temp;
     c = (n-2)*2 + dp[n-1];

    temp = sqrt(n);
     if( (int)temp == (double)temp )
         c ++;
     
     dp[n] = c;
     return c;
}    

     
int main() {
    int t, i;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 3;
    scanf("%d", &t);
    
     /* for( i = 1; i < 1562500; i++ ) {
           //printf("%d %lld  %lld \n",i, combi(i), comb(i) );
           
      }*/
      
    while(t--) {
      int n;
      unsigned long long int ans = 0;
      scanf("%d", &n);
      
      for( i = 1; i < n; i++ ) {
           int j = n-i;
           printf("%d %lld   %lld\n",i*j, comb(i*j), ans );
           
           //if( i*j > 2000 ) getch();
           ans += comb(i*j);
      }
      
      printf("%lld\n", ans );
   }
   
   //getch();
}
           
