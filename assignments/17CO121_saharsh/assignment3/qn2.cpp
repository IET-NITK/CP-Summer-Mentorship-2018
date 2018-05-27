//http://codeforces.com/problemset/problem/75/C
//http://codeforces.com/contest/75/submission/38439823
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int gcd(ll a,ll b)
{
  if(b==0) return a;
  else return gcd(b,a%b);
}
int main()
{
ll a,b,q1,q2,n;
cin>>a>>b>>n;
ll num=gcd(a,b);
ll k=sqrt(num);
vector<ll> v;
vector<ll>::iterator it;

for(ll i=1;i<=k;i++)
{
  if(num%i==0) {
    v.push_back(i);
    if(num/i!=i)
    v.push_back(num/i);}
}

sort(v.begin(),v.end());

while(n--)
{
  cin>>q1>>q2;
  it=lower_bound(v.begin(),v.end(),q2);

  if(*it>=q1&&*it<=q2) cout<<*it<<endl;

  else if(*(it-1)>=q1&&*(it-1)<=q2) cout<<*(it-1)<<endl;

  else cout<<"-1"<<endl;
}
}
