//http://codeforces.com/contest/687/problem/B
//http://codeforces.com/contest/687/submission/38678654


#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int gcd(int a,int b)
{
  if(b==0) return a;
  else return(b,a%b);
}
int main()
{
  ll n,k,temp;
  scanf("%lld%lld",&n,&k );
  ll c[n],i;
  scanf("%lld",&c[0] );  temp=c[0];
  if(c[0]==k||k==1||c[0]%k==0) {printf("Yes"); exit(0);}
  for( i=1;i<n;i++){
      scanf("%lld",&c[i] );

    temp=((temp*c[i])/gcd(c[i],temp))%k;
    if(temp==0) {printf("Yes"); exit(0);}

}
if(i==n) printf("No");
}
