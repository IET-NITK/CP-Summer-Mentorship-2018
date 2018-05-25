//assignment3 question1 , 687B
//submision link:http://codeforces.com/contest/687/submission/38543241
//code:
#include<bits/stdc++.h>
using namespace std;
long long int k;
long long int  findlcm(std::vector<long long int > v,int n)
{
    long long int  ans = v[0]; 
    for (int i = 1; i < n; i++)
        {
        	ans = ((((v[i]) * (ans))) /
                (__gcd(v[i], ans)));
        	ans=ans%k;
        }
    return ans%k;
}
int main()
{
	 long long int N,p=0;
	scanf("%lld%lld",&N,&k);
	if(k==1)
		printf("Yes");
	else
	{

	vector< long long int>v(N);
	for(long int i=0;i<N;i++)
			{
				scanf("%lld",&v[i]);
				if(k==v[i])
					{
						printf("Yes\n");
						p++;
						break;
					}
			}
		if(p==0)
		{
				p=findlcm(v,N);
			{
			if(p==0)
				printf("Yes\n");
			else
				printf("No\n");
			}
		}
	}
}
			
