#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#define MOD 1000000007
typedef long long int ll;
using namespace std;
 
char a[1004],b[1004];
ll f[1004],invf[1004],pow2[1004],pow8[1004];
int lucky[]={4,7,44,47,74,77,444,447,474,477,744,747,774,777};
 
ll modpow(ll a,ll b)
{
	if(b==0)	return 1;
	ll ans=modpow(a,b>>1);
	ans=(ans*ans)%MOD;
	if(b&1)
		ans=(ans*a)%MOD;
	return ans;
}
 
void compute(void)
{
	f[0]=1;
	pow2[0]=1;
	pow8[0]=1;
	invf[0]=1;
	for(int i=1;i<=1000;i++)
	{
		f[i]=(f[i-1]*i)%MOD;
		pow2[i]=(pow2[i-1]*2)%MOD;
		pow8[i]=(pow8[i-1]*8)%MOD;
		invf[i]=(invf[i-1]*modpow(i,MOD-2))%MOD;
	}
}
 
ll C(ll a,ll b)
{
	ll ans=(f[a]*invf[b])%MOD;
	ans=(ans*invf[a-b])%MOD;
	return ans;
}
 
ll see(ll taken,ll av)
{
	ll ans=0,i,needed,q;
	for(i=0;i<14;i++)
	{
		if(taken>lucky[i])	continue;
		needed=lucky[i]-taken;
		if(needed>av)		continue;
		q=(((C(av,needed)*pow2[needed])%MOD)*pow8[av-needed])%MOD;
		ans=(ans+q)%MOD;
	}
	//printf("**%lld\n",ans);
	return ans;
}
 
ll solve(char *s)
{
	ll ans=0,c=0;
	int l=strlen(s),i;
	for(i=0;s[i];i++)
	{
		if(s[i]>'7')
			ans=(ans+(s[i]-'0'-2)*see(c,l-i-1)+see(c+1,l-i-1)*2)%MOD;
		else if(s[i]>'4')
			ans=(ans+(s[i]-'0'-1)*see(c,l-i-1)+see(c+1,l-i-1))%MOD;
		else if(s[i]-'0')
			ans=(ans+((s[i]-'0')*see(c,l-i-1)))%MOD;
		if(s[i]=='4' || s[i]=='7')	c++;
	}
	return ans;
}
 
int main()
{
	int test,d,c;
	ll q1,q2,i;
	compute();
	//for(i=0;i<=10;i++)	printf("%lld %lld %lld %lld\n",pow2[i],pow8[i],f[i],invf[i]);
	scanf("%d",&test);
	while(test--)
	{
		scanf(" %s %s",a,b);
		q1=solve(a);
		q2=solve(b);
		//printf("%lld %lld\n",q1,q2);
		c=d=0;
		for(i=0;a[i];i++)
			if(a[i]=='7'||a[i]=='4')	c++;
		for(i=0;b[i];i++)
			if(b[i]=='7'||b[i]=='4')	d++;
		for(i=0;i<14;i++)	if(lucky[i]==d)	break;
		if(i!=14)	q2++;
		if(q1>q2)	q2+=MOD;
		printf("%lld\n",(q2-q1)%MOD);
	}
	return 0;
} 
