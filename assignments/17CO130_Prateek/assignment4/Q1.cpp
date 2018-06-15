//Assignment 4 qn1:https://www.codechef.com/problems/IPCTRAIN
//submission_link:https://www.codechef.com/viewsolution/18905863
//code:
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll T;
	cin>>T;
	while(T--)
	{
		ll N,D,d,t,s,ans=0;
		cin>>N>>D;
		vector<vector<pair<ll,ll> > > v(100002) ;
		multiset <pair<ll,ll> > m;
		multiset <pair<ll,ll> > :: iterator itr;
		for (ll i = 0; i < N; ++i)
		{
			cin>>d>>t>>s;
			v[d].push_back(make_pair(s,t));
		}
		for(ll i=1;i<=D;++i)
		{
			for(vector < pair<ll,ll> > :: iterator jtr=v[i].begin();jtr!=v[i].end();jtr++)
					{
						m.insert((*jtr));
						//cout<<"v[i].second="<<v[i].second<<endl;
					}
			if(m.size()!=0)
				{
					itr=prev(m.end());
					pair<ll,ll> p=*itr;
					m.erase(itr);
					p.second--;
					if(p.second!=0)
						m.insert(p);
					//cout<<"p.second"<<p.second<<" "<<"p.first="<<p.first<<" "<<endl;
				}
		}

		for (itr= m.begin(); itr !=m.end(); ++itr)
			ans+=((*itr).first)*((*itr).second);
		cout<<ans<<endl;
	}	
	
}