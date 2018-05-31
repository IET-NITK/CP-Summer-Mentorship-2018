//question:http://codeforces.com/problemset/problem/983/A
//solution:http://codeforces.com/contest/983/submission/38657068

//code:
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
unsigned long long int n,p,q,b,i,k,flag=0;
double a;
cin>>n;
for(i=0;i<n;i++)
{scanf("%llu%llu%llu",&p,&q,&b);
q=q/__gcd(p,q);
while(__gcd(q,b)!=1)
{q=q/__gcd(q,b);
b=__gcd(b,q);}
if(q==1)
printf("Finite\n");
else
printf("Infinite\n");}}


