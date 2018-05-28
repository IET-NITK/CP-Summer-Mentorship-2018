//https://www.codechef.com/LTIME52/problems/C00K0FF/
//https://www.codechef.com/viewsolution/18564316
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n; string s;
		map<string, int> m;
		m["cakewalk"] = 0, m["simple"] = 0, m["easy"] = 0, m["easy-medium"] = 0, m["medium"] = 0, m["medium-hard"] = 0, m["hard"] = 0;
		while(n--) {
			cin >> s; m[s]++;
		}
		if(m["cakewalk"] && m["simple"] && m["easy"] && (m["easy-medium"] || m["medium"]) && (m["medium-hard"] || m["hard"])
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}