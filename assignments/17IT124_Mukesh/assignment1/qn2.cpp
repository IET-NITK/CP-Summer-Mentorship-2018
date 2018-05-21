/*https://www.codechef.com/problems/C00K0FF
Solution:https://www.codechef.com/viewsolution/18557914*/

#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string, int> a;
void reset()
{
    a["cakewalk"] = 0;
	a["simple"] = 0;
	a["easy"] = 0;
	a["easy-medium"] = 0;
	a["medium"] = 0;
	a["medium-hard"] = 0;
    a["hard"] = 0;
}
bool solve(int n)
{
    string str;
    for(int i = 0; i != n; i++) {
		cin>>str;
		a[str]++;
    }
	if(a["cakewalk"] && a["simple"] && a["easy"] && (a["easy-medium"] || a["medium"]) && (a["medium-hard"] || a["hard"])) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
	int t;
	cin>>t;
	while(t--) {
		reset();
		int n;
		cin>>n;
		if(solve(n)) {
			cout<<"Yes"<<endl;
		}
		else {
			cout<<"No"<<endl;
		}
	}
	return 0;
}
