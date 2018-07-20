/*
problem: https://www.codechef.com/problems/IPCTRAIN
solution-link: https://www.codechef.com/viewsolution/18895500
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef map<int, int, greater<int> > mymap; 
 
struct lecturer {
	int d, t, s;
	bool operator<( const lecturer& val ) const { 
		return d < val.d; 
	}
};
 
void update_heap(int n, mymap& heap) {
	if(heap.empty() || n == 0) {
		return;
	}
	mymap::iterator it = heap.begin();
	if(it->second <= n) {
		int temp = it->second;
		heap.erase(it);
		update_heap(n-temp, heap);
	}
	else {
		it->second -= n;
	}
}
 
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n,d;
		cin>>n>>d;
		vector<lecturer> v;
		for(int i = 0; i != n; i++) {
			lecturer obj;
			cin>>obj.d>>obj.t>>obj.s;
			v.push_back(obj);
		}	
		lecturer obj;
		obj.d = d+1;
		v.push_back(obj);
		sort(v.begin(), v.end());
		mymap heap;
		for(int i = 0; i != n; i++) {
			mymap::iterator it = heap.find(v[i].s);
			if(it == heap.end()) {
				heap[v[i].s] = v[i].t;
			}
			else {
				heap[v[i].s] += v[i].t;
			}
			update_heap(v[i+1].d - v[i].d, heap);
		}
		long long sadness = 0;
		for(mymap::iterator it = heap.begin(); it != heap.end(); it++) {
			sadness += 1LL*(it->first)*(it->second);
		}
		cout<<sadness<<endl;
	}
	return 0;
} 