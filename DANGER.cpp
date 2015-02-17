#include <iostream>
#include <cmath>
using namespace std;

int main() {
	while(1) {
		char str[10];
		scanf("%s", str);
		
		if( str[0] == '0' && str[1] == '0' && str[3] == '0' )
			break;
			
		long long int num;
		num = str[0] - '0';
		num *= 10;
		num += str[1] - '0';
		num *= pow(10, str[3]-'0');
		
		int val = log2(num);
		long long ans = num - pow(2,val);
		
		ans = 2*ans + 1;
		
		printf("%lld\n", ans);
		
	}
}
