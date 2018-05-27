//question:http://codeforces.com/problemset/problem/687/B
//solution:http://codeforces.com/contest/687/submission/38648844

//code:
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
long long int n,k,i,d,j;
scanf("%lld%lld%lld",&n,&k,&d);
j=d;
if(n!=1)
{for(i=0;i<n-1;i++)
{scanf("%lld",&d);
j=((j*d)/__gcd(j,d))%k;}
if(j==0)
printf("Yes\n");
else
printf("No\n");}
else
{if(j%k==0)
printf("Yes\n");
else
printf("No\n");}}



