//https://www.codechef.com/OCT17/problems/MARRAYS

//solution link: https://www.codechef.com/viewsolution/18990575

//code:

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	long long t,n,i,j,k,m,p;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<long long>v[n],sum[n],last;
		for(i=0;i<n-1;i++)
		{
			cin>>m;
			for(j=0;j<m;j++)
			{
				cin>>p;
				v[i].push_back(p);
			}
		}
		cin>>m;
		for (j=0;j<m;j++)
			{
				cin>>p;
				last.push_back(p);
			}	
		sort(last.begin(),last.end());
		v[n-1].push_back(last[0]);
		v[n-1].push_back(last[m-1]);
		for (i=0;i<v[0].size();i++)
			{
				sum[0].push_back(0);
			}

		for (i=1;i<n;i++)
		{
			for (j=0;j<v[i].size();j++)
			{
				long long max =0;
				for (k = 0; k < v[i-1].size()-1; k++)
				{
					p=abs(v[i][j]-v[i-1][k])*i + sum[i-1][k+1];
					if(max<p)
					max=p;
				}
				p=abs(v[i][j]-v[i-1][k])*i + sum[i-1][0];
				if(max<p)
					max=p;
				sum[i].push_back(max);
				
			}
		}
		long long max =0;		
		for ( i = 0; i < sum[n-1].size(); ++i)
			{
				if(sum[n-1][i]>max)
					max=sum[n-1][i];
			}
		cout<<max<<endl;
			
	}
	return 0;
}
