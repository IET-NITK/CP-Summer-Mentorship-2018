// https://www.codechef.com/LTIME52/problems/C00K0FF/
//https://www.codechef.com/viewsolution/18596072

//code:
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	 {
		int n;
		cin>>n;
		map<string, int> s; 
		s["cakewalk"] = s["simple"] = s["easy"] = s["easy-medium"] = s["medium"] = s["medium-hard"] = s["hard"] =0;
		string str;
		for(int i = 0; i<n; i++) 
		{
			cin>>str;
			s[str]++;
		}
		if(s["cakewalk"] && s["simple"] && s["easy"] && (s["easy-medium"] || s["medium"]) && (s["medium-hard"] || s["hard"]))
		 {
			cout<<"Yes"<<endl;
	   	}
		else 
		{
			cout<<"No"<<endl;
		}
	}
	return 0;
}
