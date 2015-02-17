#include <stdio.h>
#include <stdlib.h>
 
int main() {
  long int n, m;
  char a[100005];
  
  scanf("%ld %ld", &n, &m);
  scanf(" %s", a);
 
  while(m--) {
	  long long int t, i, sum = 0;
	  scanf("%lld", &t);
	   	t--;
	  for( i = 0; i < t; i++ )
		 sum += abs( (a[t]-'0') - (a[i]-'0') );
	 
	printf("%lld\n", sum);
  }
}
