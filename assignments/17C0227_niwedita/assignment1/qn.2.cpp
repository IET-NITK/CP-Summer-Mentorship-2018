//https://www.codechef.com/LTIME52/problems/C00K0FF/

//solution code:

https://www.codechef.com/status/C00K0FF,nivi2017


code:

#include <iostream>
#include <string>
using namespace std;
 
int main() 
{
	// your code goes here
	long t;
	cin>>t;
	while(t--)
	{
	    long n;
	    int c0 = 0;
	    int c1 = 0;
       	    int c2= 0;
	    int c3= 0;
	    int c4= 0;
	    int c5= 0;
       	    int c6= 0;
            cin>>n;
	    for(long i=0;i<n;i++)
		{
	        string s;
	        cin>>s;
	        if(s == "cakewalk")
	            c0++;
	        else if(s == "easy")
	            c1++;
	        else if(s== "simple")
		    c2++;
	        else if(s == "easy-medium")
	            c3++;
	        else if(s == "medium")
	            c4++;
	        else if(s == "medium-hard")
	            c5++;
	        else if(s == "hard")
	            c6++;
		}		
	        if((c0 > 0) && (c1 > 0) && (c2 > 0) && (c3> 0 || c4> 0) && (c5 > 0 ||c6 > 0))
	        cout<<"Yes"<<endl;
	        else 
	         cout<<"No"<<endl;
	}
	return 0;
}

