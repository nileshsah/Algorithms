#include <stdio.h>


long long int dp[1562501], mul[1562501];

long long int combi( int n ) {
    // if( dp[n] != 0 )
      //   return dp[n];
    int c = 0, i , j;
   for( i = 1; i < n; i++ )
        for(  j = 1; j < n; j++ )
             if( i*j < n )
                 c++;
     
     //dp[n] = c;
     return c;
}    
     

long long int comb( int n ) {
     if( dp[n] != 0 || n == 1)
         return dp[n];
    
    if( dp[n-1] == 0 )
         comb(n-1);
         
    long long c = dp[n-1]; 
    int m = n-1, i; 
    for(  i = 1; i <= m; i++ ) {
         int j = m/i;
         if( j > mul[i] ) {
             c += j-mul[i];
             mul[i] = j;
         }
    }  
          
     dp[n] = c;
                
     return c;       
}    

     
int main() {
    int t, i;
    dp[1] = 0;
    mul[0] = 0;
    //dp[4] = 6;
    scanf("%d", &t);
    
    //printf("%d %lld  %lld \n",i, combi(i), comb(1562501) );
      for( i = 30; i < 50; i++ ) {
           printf("%d %lld  %lld \n",i, combi(i), comb(i) );
      }
      
    while(t--) {
      int n;
      unsigned long long int ans = 0, c;
      scanf("%d", &n);
      for( i = 1; i <= n/2; i++ ) {
           int j = n-i;
           c = comb(i*j);
           if( i != j )
             c *= 2;
           //printf("%d %lld   %lld\n",i, c, ans );
           ans += c;
      }
      
      printf("%lld\n", ans );
   }
   
   //getch();
}
           
