#include<bits/stdc++.h>
int main()
{
   while(1)
   {
      char *S,*T;
      S=(char *)malloc(501*sizeof(char));
      T=(char *)malloc(501*sizeof(char));
      scanf("%s%s",S,T);
      if(S[0]=='*' && T[0]=='*')
         break;
      int i=0,count=0;
      while(S[i]!='\0')
      {
         if(S[i]!=T[i])
         {
            count++;
            while(S[i]!=T[i])
            i++;
         }
         i++;
      }
      printf("%d\n",count);
   }
   return 0;
}
