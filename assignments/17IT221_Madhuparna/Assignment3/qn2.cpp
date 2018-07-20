//Problem link: http://codeforces.com/contest/75/problem/C

//Solution link : http://codeforces.com/contest/75/submission/38684784

//Code:
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll a,b;
    cin>>a>>b;
    ll g=__gcd(a,b);
   vector<ll> v;
   for(int i=1;i<=sqrt(g);++i)
   {
       if(g%i==0)
       {  v.push_back(i);
       v.push_back(g/i);
       }
       
   }
    sort(v.begin(),v.end());
    
    int len=v.size();
    /*for(int i=0;i<len;++i)
        cout<<v[i]<<endl;*/
    int n;
    cin>>n;
    while(n--)
    {
        int ans=-1;
        ll l,h;
        cin>>l>>h;
        for(int i=len-1;i>=0;--i)
        {
            if(v[i]>=l&&v[i]<=h)
            {
                ans=v[i];
                break;
            }
        }
        cout<<ans<<endl;
    }

}