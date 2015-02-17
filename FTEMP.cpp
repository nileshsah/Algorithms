#include <cstdio>
#include <vector>
#include <cmath>
#define vv(t) vector<vector<t> >
using namespace std;
typedef long long LL;

LL MOD = 1000000007;

int n;
vv(LL) s0;

void print_mat(vv(LL) x)
{
  for(int i=0;i<x.size();i++)
  {
    for(int j=0;j<x[0].size();j++)
      printf("%lld ",x[i][j]);
    printf("\n");
  }

}

void mat_mul(vv(LL) a, vv(LL) b, vv(LL)& c, int m,int k,int n)
{
  for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    {
      c[i][j] = 0;
      for(int t=0;t<k;t++)
        c[i][j] = (c[i][j] + (a[i][t]*b[t][j])%MOD)%MOD;
    }
  // print_mat(c);
}
void mat_copy(vv(LL)& a,vv(LL) b)
{
  for(int i=0;i<a.size();i++)
    for(int j=0;j<a[0].size();j++)
      a[i][j] = b[i][j];
}

LL fibo(LL N)
{
  if(N==0)
    return 0;
  else if(N==1)
    return s0[0][0]%MOD;
  else if(N==2)
    return s0[1][0]%MOD;
  vector<vector<LL> > a,b,c;
  a.resize(n);
  b.resize(n);
  c.resize(n);
  for(int i=0;i<n;i++)
  {
    a[i].resize(n);
    b[i].resize(n);
    c[i].resize(n);
  }
  a[0][0] = a[0][1] = a[1][0] = 1;
  a[1][1] = 0;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      c[i][j] = 0;
  c[0][0] = c[1][1] = 1;
  N = N-2;
  while(N)
  {
    if(N%2==1)
    { mat_mul(c,a,b,n,n,n);
      mat_copy(c,b);
    }
    mat_mul(a,a,b,n,n,n);
    mat_copy(a,b);
    N>>=1;
  }

  mat_mul(c,s0,b,n,n,1);
  // print_mat(b);
  if(b[0][0]<0)
    b[0][0]+=MOD;
  return b[0][0];
}

int main()
{
  n = 2;
  s0.resize(n);
  for(int i=0;i<n;i++)
    s0[i].resize(1);
  s0[0][0] = 1;
  s0[1][0] = 1;

  int t;
  LL N,M;

  scanf("%d",&t);
  while(t--)
  {
    scanf("%lld %lld",&N,&M);
    LL ans = (fibo(M+2)-1-(fibo(N+1)-1))%MOD;
    if(ans<0)
      ans += MOD;
    printf("%lld\n",ans);
  }
  return 0;
}
