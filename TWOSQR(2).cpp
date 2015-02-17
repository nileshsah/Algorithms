#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	
	while(t--) {
		long long n, a = 0, b;
		scanf("%lld", &n);
		
		b = sqrt(n);
		
		while(1) {
			if( a*a + b*b == n )
			 {	printf("Yes\n"); break; }
		   
		    if( a*a > n )
		     { printf("No\n"); break; }
		     
			if( a*a + b*b > n )
		     b--;
		    else
		     a++;
		     
		}
		
	}
	
}
