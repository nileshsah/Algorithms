#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <cstring>
#define ll long
#define get(a) scanf("%ld", &a)
#define rep(n) for( ll i = 0; i < n; i++ )
#define repVector(v)  for(vector<ll>::iterator it = v.begin(); it != v.end(); it++ )
#define all(c) c.begin(), c.end()
#define repu(a,n) for( ll i = a; i < n; i++ )
#define pb push_back
using namespace std;

int main() {
    ll t;
    get(t);
  //  cin.ignore();
    while(t--) {
      char str[500];
      scanf("%s", &str);
      
      stack<char> op;
      queue<char> var;
      op.push('(');
      
      for( ll i = 0; str[i] != '\0'; i++ )
        switch( str[i] ) {
          case '+':
          case '-':
          case '*':
          case '/':
          case '^':
          case '(':
              op.push(str[i]);
              break;
          case ')':
              while( op.top() != '(' ) {
                var.push( op.top() );
                op.pop();
              }
              op.pop();
              break;
          default:
              var.push(str[i]);
        }
          
           while( op.top() != '(' ) {
                var.push( op.top() );
                op.pop();
              }
           op.pop();
      
      while(!var.empty()) {
       printf("%c", var.front());
       var.pop();
      }
      printf("\n");
  }
}
          
      
