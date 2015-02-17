#include <stdio.h>

int main() {
    long long unsigned int a;
    scanf("%llu", &a);
    
    if( a%3 == 0 || (a-1)%6 == 0 ) {
        printf("yes");
    }
    else
        printf("no");
    
    return 0;
}
