//assignment 5 question1:https://www.codechef.com/problems/MARRAYS
//solution link:https://www.codechef.com/viewsolution/19087552



//code:

#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
long long int ma(long long int a,long long int b){
if(a>b)
return a;
return b;}
int main(){
long long int t,a,a1,i,j,k;
cin>>t;
while(t--)
{long long int n;
cin>>n;
vector<vector<long long int>>v(n),sum(n);
int s[n];
for(i=0;i<n;i++)
{cin>>s[i];
sum[i].resize(s[i],0);
v[i].resize(s[i],0);
for(j=0;j<s[i];j++)
{cin>>a;
v[i][j]=a;}}
long long int max=v[0][0],min=v[0][0];
//cout<<max<<" "<<min<<endl;
for(i=1;i<s[0];i++)
{if(v[0][i]>max)
max=v[0][i];
if(v[0][i]<min)
min=v[0][i];
//cout<<v[0][i]<<endl;
}
//cout<<max<<" "<<min<<endl;
for(i=0;i<s[1];i++)
sum[1][i]=ma(abs(max-v[1][i]),abs(v[1][i]-min));
for(i=2;i<n;i++)
{assert(i<n);
for(j=0;j<s[i];j++)
{a1=sum[i-1][0]+(abs(v[i-1][s[i-1]-1]-v[i][j])*i);
for(k=s[i-1]-1;k>=1;k--)
a1=ma(a1,(sum[i-1][k]+abs(v[i-1][k-1]-v[i][j])*i));
sum[i][j]=a1;}}
long long int res=0;
//assert(i>n);
for(i=0;i<s[n-1];i++)
if(res<sum[n-1][i])
res=sum[n-1][i];
cout<<res<<endl;}}




