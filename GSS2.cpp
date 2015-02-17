/* Stepping Stones
Name:Harsh Grover
reg nO: 12BCE0013*/



#include<stdio.h>
#include<conio.h>
int main()
{
 
 int n,len,d,arr_dist[1000],i,j;
 scanf("%d%d%d",&n,&len,&d);
 float s,arr_p[1001],arr[10000]={0},max =0;     
 for(i=0;i<n;i++)
 scanf("%f",&arr_p[i]);
 
 for(i=0;i<n;i++)
   scanf("%d",&arr_dist[i]);
if(arr_dist[0] <=len)
arr[arr_dist[0]] = arr_p[0];
else
arr[arr_dist[0]] =0;
//printf("%f",arr[arr_dist[0]]);
 for(i=1;i<n;i++)
 {
                  
     max = 0;
     s = arr_dist[i];
     for(j=i-1;j>=0;j--)
     {
       if(s - arr_dist[j] <= len)                
       {
         if(arr[arr_dist[j]]>=max)
          max = arr[arr_dist[j]] * arr_p[i];               
         
       }              
     }
     if(s<=len)
     {
               if(arr_p[i] >max)
               max = arr_p[i];
     }
 arr[arr_dist[i]] = max;
}
if(arr[arr_dist[n-1]] !=0)
  printf("%f",arr[arr_dist[n-1]]);
  
else
printf("IMPOSSIBLE");
 getch();   
 return 0;   
}

