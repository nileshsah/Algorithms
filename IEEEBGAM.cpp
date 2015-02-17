#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		double n;
		cin >> n;
		
		double ans = double(n-1)/n + (1/n)*( 1/double(n+1) );
		printf("%0.8lf\n", ans);
	}
}

