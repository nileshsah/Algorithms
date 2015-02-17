#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<conio.h>
using namespace std;
int main()
{
char s[20];
char b[2];
cout<<"enter marks range till max 20"<<"\n";
gets(s);
int i;
int c=0;
int d=0;
int e=1;
int g=0;
int h=0;
for(i=0;s[i]!='\0';i++)
{
                       c++;
                       }
                       if(c>=20)
                       {
                                cout<<"max length exceeded";
                                }
                                else
                                {
                                                           
                                     while(e<=(c-1))
                                    {
                                 for(i=d;i<=e;i++)
                                 {
                                   b[g]=s[i];
                                   g++;
                                   }
                                   if(b[0]!='0')
                                   {
                                   if(b[0]=='2')
                                       {
                                           if(b[1]=='0')
                                           {                  
                                     h++;
                                     }
                                     }
                                   
                                   
                                   else if(b[0]=='1')
                                     {
                                          if(b[1]=='0' ||   b[1]=='1' ||   b[1]=='2' ||   b[1]=='3' ||   b[1]=='4' ||   b[1]=='5' ||   b[1]=='6' ||   b[1]=='7' ||   b[1]=='8' ||   b[1]=='9')
                                          {
                                                       h++;
                                                       }
                                     
                                     }
                                     }
                                   
                                   
                                   
                                   
                                   
                            
                                     
                                     d++;
                                     e++;
                                      g=0;                                       
                                     } 
                                      d=0;
                                      e=1;  
                                    if(c%2==0)
                                   {
                                              if(c>2)
                                              {                         
                                     while(e<=(c-1))
                                    {
                                 for(i=d;i<=e;i++)
                                 {
                                   b[g]=s[i];
                                   g++;
                                   }
                                   if(b[0]!='0')
                                   {
                                       if(b[0]=='2')
                                       {
                                           if(b[1]=='0')
                                           {                  
                                     h++;
                                     }
                                     }
                                     else if(b[0]=='1')
                                     {
                                          if(b[1]=='0' ||   b[1]=='1' ||   b[1]=='2' ||   b[1]=='3' ||   b[1]=='4' ||   b[1]=='5' ||   b[1]=='6' ||   b[1]=='7' ||   b[1]=='8' ||   b[1]=='9')
                                          {
                                                       h++;
                                                       }
                                     
                                     }
                                     d+=2;
                                     e+=2;
                                      g=0;                                       
                                     } 
                                     }
                                    
                                    
                                    }
                                    }
                                    
                                    if(c%2!=0)
                                    {
                                    cout<<"\n"<<h+1;
                                    }
                                    else if(c%2==0)
                                    
                                    {
                                         if(c>2)
                                        cout<<"\n"<<h;
                                        else
                                        cout<<"\n"<<h+1;
                                        }
                                        
                                    
                           
                                    
                                } 
                       
               getch();
               }
