/* QUESTION :- https://www.codechef.com/problems/IPCTRAIN
   SUB. LINK :- https://www.codechef.com/viewsolution/18892284 */
   
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios_base::sync_with_stdio(false),cin.tie(0)
#define f first
#define s second
#define pip pair <int, pair<int,int> >
bool compare(pip p1,pip p2){ return p1.s.f<p2.s.f ;}
int main()
{
    fastio;
    priority_queue < pip > q;
    int t;
    cin>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        pip p[n+1];
        for(int i=0;i<n;++i)
            cin>>p[i].s.f>>p[i].s.s>>p[i].f;
        sort(p,p+n,compare);
        ll ans=0;
        int j=0;
        pip x;

        for(int i=1;i<=d;++i)
        {
            while(j<n&&p[j].s.f==i)
                q.push(p[j++]);
            if(!q.empty())
            {
                x = q.top();
                x.s.s--;
                q.pop();
                if(x.s.s)
                    q.push(x); 
            }
        }
        while(!q.empty())
        {
            x = q.top();
            ans += 1LL * x.s.s * x.f;
            q.pop();
        }
        cout<<ans<<"\n";
    }
} 
