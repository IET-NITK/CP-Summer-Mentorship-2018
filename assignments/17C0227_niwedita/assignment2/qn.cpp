//https://www.hackerrank.com/contests/university-codesprint-3/challenges/bobs-game/


//Solution code:

#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main()
{
int t,i,j,n;
int g[1024][1024];
char s[1024][1024];
cin>>t;
while(t--)
{
	cin>>n;
	for(i=0;i<n;i++)
	cin>>s[i];
	for(i=0;i<n;i++)
	{	
		for(j=0;j<n;j++)
		if (s[i][j]=='X')
		{
			g[i][j]=-1;
			continue;
		}
		set<int>w;
		if(i>0)
		w.insert(g[i-1][j]);
		if(j>0)
		w.insert(g[i][j-1]);
		if(i>0 && j>0)
		w.insert(g[i-1][j-1]);
		g[i][j]=0;
		while (w.find(g[i][j])!=w.end())
		g[i][j]++;
	}
}
int a=0;
for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	if(s[i][j]=='K')
	a^=g[i][j];
if(a==0)
cout<<"lose"<<endl;
else
{
	int c=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			if(s[i][j]!='K')
			continue;
			vector<int> v;
			if(i>0 && s[i-1][j]!='X')
			v.push_back(g[i-1][j]);
			if(j>0 && s[i][j-1]!='X')
			v.push_back(g[i][j-1]);
			if(i>0 && j>0 && s[i-1][j-1]!='X')
			v.push_back(g[i-1][j-1]);
			vector<int>::iterator itr=v.end();
			if((a ^ *itr ^ g[i][j])==0)
			c++;
		}
		cout<<"win"<<endl;
}	
}

