//problem: https: //www.codechef.com/problems/MARRAYS
//solution link: https://www.codechef.com/viewsolution/19257582
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
 
typedef long long ll;
 
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> m(n);
		vector< vector<int> > a(n);
		for(int i =0; i < n; i++) {
			cin >> m[i];
			a[i].resize(m[i]);
			for(int j =0; j < m[i]; j++) cin >> a[i][j];
		}
		vector< vector<ll> > s(n);
		for(int i =0; i < n; i++) s[i].resize(m[i],0);
		for(int i =1; i < n; i++) {
			ll max1 =-1e9, max2 =-1e9;
			for(int j =0; j < m[i-1]; j++) {
				max1 =max(max1,s[i-1][(j+1)%m[i-1]]-1LL*i*a[i-1][j]);
				max2 =max(max2,s[i-1][(j+1)%m[i-1]]+1LL*i*a[i-1][j]);
			}
			for(int j =0; j < m[i]; j++)
				s[i][j] =max(s[i][j],max(max1+1LL*i*a[i][j],max2-1LL*i*a[i][j]));
		}
		ll ans =0;
		for(int i =0; i < m[n-1]; i++) ans =max(ans,s[n-1][i]);
		cout << ans << "\n";
	}
}