#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <cstring>
#define ll int
#define get(a) scanf("%d", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define pb push_back
using namespace std;

int main() {
	long t = 0;
	while(1) {
		t++;
		char str[3000];
		scanf("%s", &str);
		
		if( str[0] == '-' )
			break;
			
		long count = 0;
		long check = 0;

		
		repu( 0, strlen(str) ) {
			if( str[i] == '}' ) {
				check--;
				if( check < 0 )
				 { check = 1; count++; }
			}
			else
				check++;	
		}
		
		cout << t << ". " << count + check/2 << endl;
		
	}
}
