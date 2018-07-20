//assignment 4 question1:https://www.codechef.com/problems/IPCTRAIN
//solution link:https://www.codechef.com/viewsolution/18917581

#include<iostream>
#include<vector>
#include<map>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
int t;
scanf("%d",&t);
while(t--)
{ll n,d,sad=0,da,t,s;
scanf("%lld%lld",&n,&d);
vector<pair<ll, pair <ll,ll> >> v(n);
priority_queue<pair<ll,ll>> any;
for(ll i=0;i<n;i++)
{scanf("%lld%lld%lld",&da,&t,&s);
v[i].first=da;
v[i].second.first=t;
v[i].second.second=s;
sad+=t*s;}
sort(v.begin(),v.end());
int j=0;
for(ll i=1;i<=d;)
{if(v[j].first==i)
{any.push( make_pair(v[j].second.second,v[j].second.first) );
//cout<<any.begin()->first<<endl<<any.begin()->second<<endl;
j++;
continue;}
else
i++;
if(!any.empty())
{
//cout<<it->first<<endl<<it->second<<endl;
pair<ll,ll>p=any.top();
//cout<<any.top().first<<endl<<any.top().second<<endl;
any.pop();
p.second-=1;
sad-=p.first;
if(p.second)
any.push(p);}}
printf("%lld\n",sad);}}
