//https://www.codechef.com/COOK85/problems/GAMSTICK/

//code: i am sending code as i am not able to figure out my fault in this program but its not right as per codechef site.


#include <iostream>
using namespace std;
int main()
{
int t;
cin>>t;
while(t--)
{
	int x1,x2,x=0;
	long long y1,y2,n,y3;
	cin>>n>>x1>>y1>>x2>>y2;
	if(y1==y2)
	{
		cout<<"Draw"<<endl;
		continue;
	}
	if(y1>y2)
	{
		y1=n+1-y1;
		y2=n+1-y2;
	}
	y3=y2-y1;
	if(x1==x2)
	{
		if(y3%2==0)
		y1++;
		y3--;
		y3/=2;
		y1+=y3;
		y2-=y3;
		if(n%2==0)
		{
			if(y1<(n/2))
			cout<<"Slava"<<endl;
			else if(y1==(n/2))
			cout<<"Draw"<<endl;
			else
			cout<<"Miron";
		}
		else
		{
			if(y1<=(n/2))
			cout<<"Slava"<<endl;
			else
			cout<<"Miron"<<endl;
		}
	}
	else
	{
		if(y3==1)
		{
			if(y1<=(n/2))
			cout<<"Draw"<<endl;
			else
			cout<<"Miron"<<endl;
			continue;
		}
		if(y3==0)
		{
			cout<<"Draw"<<endl;
			continue;
		}
		if(y3%2==0)
		{
		x=1;
		y1++;
		}
		y3--;
		y3/=2;
		y1+=y3;
		y2-=y3;
		if(n%2==0)
		{
			if(y1<(n/2))
			{
				if(x==1)
				cout<<"Slava"<<endl;
				else
				{
					if((1+y1)==(n/2))
					cout<<"Draw"<<endl;
					else
					cout<<"Slava"<<endl;
				}
			}
			else if(y1==(n/2))
			cout<<"Draw"<<endl;
			else
			{
				if(x==0)
				cout<<"Miron"<<endl;
				else
				{
					if((y1-1)==(n/2))
					cout<<"Draw"<<endl;
					else
					cout<<"Miron"<<endl;
				}
			}
		}
		else
		{
			if(y1<=(n/2))
			{
				if(x==1)
				cout<<"Slava"<<endl;
				else
				{
					if(y1==(n/2))
					cout<<"Draw"<<endl;
					else
					cout<<"Slava"<<endl;
				}
			}
			else
			{
                       		if(x==0)
				cout<<"Miron"<<endl;
				else
				{
					if((y1-1)==(n/2))
					cout<<"Draw"<<endl;
					else
					cout<<"Miron"<<endl;
				}
			}
		}
	}
}
}





