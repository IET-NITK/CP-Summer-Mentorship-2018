//https://www.codechef.com/problems/C00K0FF
// solution link : https://www.codechef.com/viewsolution/18542796

// code : 

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		map<string, int> s;
		s["cakewalk"] = 0;
		s["simple"] = 0;
		s["easy"] = 0;
		s["easy-medium"] = 0;
		s["medium"] = 0;
		s["medium-hard"] = 0;
		s["hard"] = 0;
		string str;
		for(int i = 0; i != n; i++) {
			cin>>str;
			s[str]++;
		}
		if(s["cakewalk"] && s["simple"] && s["easy"] && (s["easy-medium"] || s["medium"]) && (s["medium-hard"] || s["hard"])) {
			cout<<"Yes"<<endl;
		}
		else {
			cout<<"No"<<endl;
		}
	}
	return 0;
}