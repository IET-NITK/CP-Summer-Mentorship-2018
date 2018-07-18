//problem: http: //codeforces.com/problemset/problem/983/A
//soution link: http://codeforces.com/contest/983/submission/40465508

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
    while(b != 0) {
       ll temp = a;
       a = b;
       b = temp%b;
    }
    return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin>>n;
	while(n--) {
		ll p,q,b;
		cin>>p>>q>>b;
		q = q/gcd(p,q);
		b = gcd(b,q);
		while(b != 1) {
			while(q%b == 0) q /= b;
			b = gcd(q,b);
		}
		if(q == 1) cout<<"Finite\n";
		else cout<<"Infinite\n";
	}
	return 0;
}