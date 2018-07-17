//submission link:https://www.codechef.com/submit/complete/19258844
//code
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
	ll T;
	cin>>T;
	while(T--)
	{
		ll n;
		cin>>n;
		vector<vector<ll> > v(n),ans(n);
		vector<ll>  v_size(n);
		for(ll i=0;i<n;++i)
		{
			cin>>v_size[i];
			v[i].resize(v_size[i],0);
			ans[i].resize(v_size[i],0);
			for(ll j=0;j<v_size[i];++j)
				cin>>v[i][j];
		}
		for(ll i=1;i<n;++i)
		{
			for(ll j=0;j<v_size[i];++j)
			{
				for(ll k=0;k<v_size[i-1];++k)
					ans[i][j]=max(ans[i][j],ans[i-1][(k+1)%v_size[i-1]]+(abs(v[i-1][k]-v[i][j]))*i);
				//printf("i=%llu j=%llu ans[i][j]=%llu \n",i,j,ans[i][j]);
			}
		}
		ll res=0;
		for(ll i=0;i<v_size[n-1];++i)
			res=max(res,ans[n-1][i]);
		cout<<res<<endl;
	}
}