//PROBLEM: https://www.codechef.com/problems/IPCTRAIN
//SOLUTION: https://www.codechef.com/viewsolution/18894928

//CODE:
#include<bits/stdc++.h>
#define ll long long
using namespace std;
class comp {
public:
    bool operator()(pair < ll,pair<ll, ll>> a, pair < ll,pair<ll,ll>> b) const {
        return a.first < b.first;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        vector<pair<ll,pair<ll,ll>>> v;
        ll day,teach,sad;
        for(int i=0;i<n;++i)
        {
            cin>>day>>teach>>sad;
            v.push_back(make_pair(day,make_pair(sad,teach)));
        }
        sort(v.begin(),v.end(),comp());
        priority_queue<pair<ll,ll>> q;
        int in=0;
        for(int i=1;i<=d;++i)
        {
            while(in<n&&v[in].first==i)
            {
                q.push(make_pair(v[in].second.first,v[in].second.second));
                in++;
            }
            if(q.size()!=0)
            {
                ll f=q.top().first;
                ll s=q.top().second;
                q.pop();
                if(s>1)
                q.push(make_pair(f,s-1));
            }
            
        }
        int siz=q.size();
        ll ans=0;
        for(int i=0;i<siz;++i)
        {ll f=q.top().first;
                ll s=q.top().second;
            ans+=f*s;
         q.pop();
        }
        cout<<ans<<endl;
    }
} 