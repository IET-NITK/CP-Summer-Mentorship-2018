//Problem :http://codeforces.com/contest/983/problem/A
//Solution:http://codeforces.com/contest/983/submission/38692680

code:
#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
int main()
{
   int t;
    cin>>t;
    while(t--)
    {
        ll p,q,b;
       scanf("%Lu %Lu %Lu",&p,&q,&b);
    if(p%q==0 || b%q==0)
       printf("Finite\n");
       else
       {
           ll g=__gcd(p,q);
           q=q/g;
            g=__gcd(q,b);
           q=q/g;
         
           while(g>1)
           {
               g=__gcd(q,g);
               q=q/g;
               
           }
           if(b%q==0 || q%b==0)
                 printf("Finite\n");
           else{
                      printf("Infinite\n");
           }
           
       }
    
        
    }
    
}