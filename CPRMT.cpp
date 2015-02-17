#include <iostream>
#include <cstring>
#define ll int
#define rep(n) for( ll i = 0; i < n; i++ )
#define repu(a,n) for( ll i = a; i < n; i++ )
#define min(a,b) a > b ? b : a
using namespace std;

int main() {
	char a[2000], b[2000]; 
	while( scanf("%s%s",&a, &b) != -1 ) {
		int x1[300] = {0}, x2[300] = {0}, x[300] = {0};
		
		rep( strlen(a) )
			x1[a[i]]++;
		rep( strlen(b) )
			x2[b[i]]++;
		
		repu( 97, 123 ) {
		  x[i] = min( x1[i], x2[i] );
		  while( x[i]-- )
		  	printf("%c", char(i) );		
		}
		
		printf("\n");
		
		
	}
}
