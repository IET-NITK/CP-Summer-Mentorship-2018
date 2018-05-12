#include<iostream> // codechef link solution- https://www.codechef.com/viewsolution/18435448
using namespace std;
 
int main()
{
	int amt=0;
	double bal=0;
	
	cin>>amt;
	cin>>bal;
	
	bool check1=(amt>0)&&((amt+0.5)<bal);
	bool check2=(amt%5)==0;
	
	if(check1&&check2)
	{
		bal=bal-amt-0.5;
		cout<<bal;
	}
	else cout<<bal;
	
	return 0;
	
	
}
