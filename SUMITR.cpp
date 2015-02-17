#include <iostream>
#define F(i,a,b) for(int i=a;i<=b;i++) 
using namespace std;
main(){int t;cin>>t;F(k,1,t){int n,m=0,a[200][200]={0};cin>>n;F(i,1,n)F(j,1,i){cin>>a[i][j];a[i][j]+=max(a[i-1][j-1],a[i-1][j]);}F(i,1,n)m=max(a[n][i],m);cout<<m<<"\n";}}
