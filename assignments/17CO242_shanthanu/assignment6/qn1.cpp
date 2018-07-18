//Problem: https: //www.codechef.com/ALMOCK01/problems/CHEFD/
//solution link: https://www.codechef.com/viewsolution/19141363

#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i = 0; i < n; i++)
typedef long long ll;

int n;  // array size

class Segment_tree {
	private: 
					const static int N = 1e5;  // limit for array size
	public:
					int t[2 * N];
					void build();
					void modify(int l, int r, int value);
					int query(int p);
					void push();
}p[4];

void Segment_tree::build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void Segment_tree::modify(int l, int r, int value) {
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) t[l++] += value;
    if (r&1) t[--r] += value;
  }
}

int Segment_tree::query(int p) {
  int res = 0;
  for (p += n; p > 0; p >>= 1) res += t[p];
  return res;
}

void Segment_tree::push() {
  for (int i = 1; i < n; ++i) {
    t[i<<1] += t[i];
    t[i<<1|1] += t[i];
    t[i] = 0;
  }
}

int divide(int a, int k, int max) {
	while(max-- && a%k==0) a/=k;
	return a;
}

int main() {
	int m;
	cin>>n;
	int a[n];
	f(i,n) {
		cin>>a[i];
		p[2-2].t[n+i] = p[3-2].t[n+i] = p[5-2].t[n+i] = 0;
	}
	cin>>m;
	while(m--) {
		int q;
		cin>>q;
		if(q == 1) {
			int l,r,t;
			cin>>l>>r>>t;
			l--;r--;
			p[t-2].modify(l, r+1, 1);
		}
		else {
			int l,d;
			cin>>l>>d;
			l--;
			a[l] = d;
			p[2-2].modify(l,l+1,-p[2-2].query(l));
			p[3-2].modify(l,l+1,-p[3-2].query(l));
			p[5-2].modify(l,l+1,-p[5-2].query(l));
		}
	}
	p[2-2].push();
	p[3-2].push();
	p[5-2].push();
	f(i, n) {
		a[i] = divide(a[i], 2, p[2-2].t[n+i]);
		a[i] = divide(a[i], 3, p[3-2].t[n+i]);
		a[i] = divide(a[i], 5, p[5-2].t[n+i]);
		cout<<a[i]<<" ";
	}
  return 0;
}