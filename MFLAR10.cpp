#include <bits/stdc++.h>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define pb push_back
#define min(a,b) ( (a < b) ? a : b )
#define absol(a) a >= 0 ? a : -a
#define FOR(i,a,b) for( ll i = a; i <= b; i++ )
#define matrix vector< vector<ll> >
#define MOD 1000000007
using namespace std;

int main() {
	char str[5000];
	while( cin.getline( str, 5000 ) ) {
		if( str[0] == '*' )
			break;
			
		string s(str);
		size_t ff = 0;
		
		while( s[ff] == ' ' ) { ff++; }
		
	    char match = tolower(s[ff]);
		
		ff = s.find(" ", ff);
		bool flag = true;
				
		while(ff != string::npos ) {
			if( ff+1 < s.size() && s[ff+1] != ' ' && tolower(s[ff+1]) != match )
			 { flag = false; break; }
			ff = s.find(" ",ff+1);
		}
		
		if(flag)
		  printf("Y\n");
		else
		  printf("N\n");
	}
}
