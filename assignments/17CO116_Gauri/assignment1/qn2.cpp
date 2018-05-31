//https://www.codechef.com/problems/C00K0FF
// solution link : https://www.codechef.com/viewsolution/18542796
 
#include <iostream>
#include <map>
#include <string>
using namespace std;
 
int main() {
 int T,N,i;
 string str;
 map<string, int> s;
 cin>>T;
 while(T--)
 { cin>>N;
   s["cakewalk"] = 0;
   s["simple"] = 0;
   s["easy"] = 0;
   s["easy-medium"] = 0;
   s["medium"] = 0;
   s["medium-hard"] = 0;
   s["hard"] = 0;
   for(i = 0; i != N; i++) 
   { cin>>str;
     s[str]++;
    }
   if(s["cakewalk"] && s["simple"] && s["easy"] && (s["easy-medium"] || s["medium"]) && (s["medium-hard"] || s["hard"])) 
    cout<<"Yes\n";
   else 
    cout<<"No\n";
	
  }
	return 0;
} 