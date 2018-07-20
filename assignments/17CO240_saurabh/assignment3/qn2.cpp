//question:http://codeforces.com/problemset/problem/75/C
//solution:http://codeforces.com/contest/75/submission/38640617

//code:
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
long long int n,i,a,b;
cin>>a>>b>>n;
long long int f=__gcd(a,b);
vector<long long int>v;
long long int flag=0,res,e;
for(i=1;i<=sqrt(f);i++)
{if(f%i==0)
{v.push_back(i);
if(i*i!=f)
v.push_back(f/i);}}
sort(v.begin(),v.end());
for(i=0;i<n;i++)
{long long int c,d;
cin>>c>>d;
e=c;
flag=0;
while (e<=f&&e<=d)
{vector<long long int>::iterator lower;
	lower = lower_bound (v.begin(), v.end(), e);
	 if(*lower>=c&&*lower<=d)
{res=*lower;
flag=1;}
e=(*lower)+1;}
if(flag==0)
cout<<-1<<endl;
else
cout<<res<<endl;}}


