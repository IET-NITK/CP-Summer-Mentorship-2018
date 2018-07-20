// https://www.codechef.com/LTIME52/problems/C00K0FF/
// solution link : https://www.codechef.com/viewsolution/18542245


//code :

#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
int main(){
int t,n;
string s;
vector <int> a={0,0,0,0,0};
cin>>t;
for(int i=0;i<t;i++)
{cin>>n;
vector <int>::iterator it=a.begin();
for(int j=0;j<n;j++)
{cin>>s;
if(s=="cakewalk")
(*it)++;
else if(s=="simple")
(*(it+1))++;
else if(s=="easy")
(*(it+2))++;
else if(s=="easy-medium"||s=="medium")
(*(it+3))++;
else if(s=="medium-hard"||s=="hard")
(*(it+4))++;}
it=a.begin();
if(((*it)>=1)&&((*(it+1))>=1)&&((*(it+2))>=1)&&((*(it+3))>=1)&&((*(it+4))>=1))
cout<<"Yes"<<endl;
else
cout<<"No"<<endl;
for(it=a.begin();it!=a.end();it++)
*it=0;}}



