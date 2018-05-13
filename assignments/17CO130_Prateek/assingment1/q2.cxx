//https://www.codechef.com/submit/complete/18549386
#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int T;
	scanf("%lld",&T);
	while(T--)
	{
		long long int N;
		int v[]={1,1,1,1,1};
		scanf("%lld%*c",&N);
		while(N--)
		{
			string s;
			getline(cin,s);
			if(s.compare("cakewalk")==0)
				v[0]--;
			if(s.compare("simple")==0)
				v[1]--;
			if(s.compare("easy")==0)
				v[2]--;
			if(s.compare("easy-medium")==0||s.compare("medium")==0)
				v[3]--;
			if(s.compare("medium-hard")==0||s.compare("hard")==0)
				v[4]--;
		}
		int c=0;
		for(int i=0;i<5;i++)
			if(v[i]>0)
				c++;
		if(c>0)
			printf("No\n");
		else
			printf("Yes\n");
		}
}
			
			
