#include <iostream>
using namespace std;

int main() {
    long t, count = 1;
    scanf("%ld", &t);
    
    while(t--) {
      long long unsigned int r;
      scanf("%lld", &r);
      
      long long unsigned int ans = 4*r*r;
      printf("Case %ld: %lld.25\n", count, ans);
      count++;
    }
}
