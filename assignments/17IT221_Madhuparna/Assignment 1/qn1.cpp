Question:https://www.codechef.com/problems/GAMSTICK/
Solution:https://www.codechef.com/viewsolution/19261931
Code:
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       ll n,x1,x2,y1,y2;
        cin>>n>>x1>>y1>>x2>>y2;
        string s1="Miron",s2="Slava";
          if(y1==y2)
                cout<<"Draw"<<endl;
        else if(x1==x2)
        {      if(y1>y2)
            {
                y1=n+1-y1;
                y2=n+1-y2;
                
            }
            ll mid=(y1+y2)/2;
            if((2*mid)>(2*n-2*mid))
                cout<<s1<<endl;
            else if(2*mid<(2*n-2*mid))
                cout<<s2<<endl;
            else
                cout<<"Draw"<<endl;
        }
        else{
           
            
             if(abs(y2-y1)==1)
            {
                   if(y1>y2)
            {
                y1=n+1-y1;
                y2=n+1-y2;
                
            }
                if((2*y1>2*(n-y1)))
                    cout<<"Miron"<<endl;
                else
                    cout<<"Draw"<<endl;
            }
            else{
                 if(y1>y2)
            {
                y1=n+1-y1;
                y2=n+1-y2;
                
            }
          
                ll cent = y2 - y1 - 2LL;
	        y1 += ( cent + 1 ) / 2;
	           y2 -= cent / 2;
 
                if(y1>((n-y1)))
                    cout<<s1<<endl;
                else if(2*(y1+1)<(2*(n-y1-1)))
                    cout<<s2<<endl;
                else
                    cout<<"Draw"<<endl;
            }
        }
        
    }
} 
