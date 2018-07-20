// problem:Assignmrnt3 2nd question -75C
// link:http://codeforces.com/problemset/submission/75/38532512
#include<bits/stdc++.h>
using namespace std;
int main()
{
		long long int a,b,i,j;
	scanf("%lld%lld",&a,&b);
	vector<long long int>va;
	vector<long long int>vb;
	vector<long long int >vab;

	for( i=1;i*i<a;i++)
		if(a%i==0)
			va.push_back(i);
	while(i>=1)
		{
			if(a%i==0)
			va.push_back(a/i);
			i--;
		}
	for( j=1;j*j<b;j++)
		if(b%j==0)
			vb.push_back(j);
	while(j>=1)
		{
			if(b%j==0)
			vb.push_back(b/j);
			j--;
		}
	set_intersection(va.begin(),va.end(),vb.begin(),vb.end(),back_inserter(vab));
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			long long int low,high;
			scanf("%lld%lld",&low,&high);
			int num;
			num=upper_bound(vab.begin(),vab.end(),high)-vab.begin();
			num--;
			if(num==-1||vab[num]<low)
				printf("-1\n");
			else
				printf("%lld\n",vab[num]);
		}
		return 0;
}
