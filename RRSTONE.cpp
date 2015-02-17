#include <stdio.h>
//#include <conio.h>
int main() {
    long long int a[100005], n, k, i, max, min;
    scanf("%lld %lld", &n, &k );
    
    for( i = 0; i < n; i++ )
         scanf( "%lld", &a[i] );
    
    max = a[0];
    min = a[0];
    for( i = 0; i < n; i++ ){
         if( a[i] > max )
             max = a[i];
         if( a[i] < min )
             min = a[i];
    }
    
    if( k == 0 ) {
        for( i = 0; i < n; i++ )
             printf("%lld ", a[i]);
    }
    else if( k%2 == 0 ) {
        long long int fact = -min;
        for( i = 0; i < n; i++ )
             printf("%lld ", fact+a[i]);
    }
    else if( k%2 != 0 ) {
        long long int fact = max;
        for( i = 0; i < n; i++ )
             printf("%lld ", fact-a[i]);
    }
    
    //getch();
}
