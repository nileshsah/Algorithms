#include <stdio.h>

int main() {
    long long int i, j, a, b, t, step = 0;
    scanf("%lld", &t);

while(t--) {             
    step = 0;
    scanf("%lld %lld", &i, &j);
    a= i; b=j;
    while( a!=b ) {
           if( a > b )
               a /= 2;
           else
               b /= 2;
               
           step++;
    }
    
    printf("%d\n", step);
}

}
           
    
    
