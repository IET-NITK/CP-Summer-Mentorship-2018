// https://www.codechef.com/LTIME52/problems/C00K0FF/
//https://www.codechef.com/submit/complete/18536726

//code:
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;++i)
    {
        int n;
        scanf("%d",&n);
        char s[1000001][20];
        for(int j=0;j<n;++j)
          scanf("%s",s[j]);
        
        //sort(s,s+n);
        char p[7][20]={"cakewalk","easy","easy-medium","hard","medium","medium-hard","simple"};
        int store[7]={0};
        int in=0;
        int flag=1;
        for(int j=0;j<n;++j)
        {
           for(int k=0;k<7;++k)
           {
               if(strcmp(s[j],p[k])==0)
               {
                   store[k]++;
                   break;
               }
           }
        }
       
        if(store[0]!=0&&store[1]!=0&&store[6]!=0&&(store[2]!=0||store[4]!=0)&&(store[3]!=0||store[5]!=0))
            printf("Yes\n");
        else
            printf("No\n");
    }
}