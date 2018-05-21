//http://codeforces.com/problemset/problem/75/C

// Solution link: http://codeforces.com/contest/75/submission/38471378


//code:



#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
vector<int>d;
int GCD(int m,int n)
{
	int temp;
	if(m<n)
	{
		temp=m;
		m=n;
		n=temp;
	}
	if(n==0)
	return m;
	return GCD(n,m%n);
}	
void all_d(int g)
{
	int rt= sqrt(g);
	for(int i=1;i<=rt;i++)
	{
		if(g%i==0)
		{
			d.push_back(i);
			d.push_back(g/i);
		}
	}
	if(d.back()==rt)
	d.pop_back();
	sort(d.begin(),d.end());
}
int main()
{
	int a,b,n,low,high;
	cin>>a>>b;
	all_d(GCD(a,b));
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>low>>high;
		int c;
		c = upper_bound(d.begin(),d.end(),high)-d.begin();
		cout<<((c>0 && low<=d[c-1])? d[c-1] : -1)<<endl;
	}
	return 0;
}
		


