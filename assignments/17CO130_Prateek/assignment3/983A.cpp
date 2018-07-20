// Assignment3 3rd question , 983A
// Submission link:http://codeforces.com/problemset/submission/983/38552750
//code:
#include<bits/stdc++.h>
using namespace std;
int main()
{
	long int n;
	scanf("%ld",&n);
	while(n--)
	{
		unsigned long long  int p,q,b;
		scanf("%llu%llu%llu",&p,&q,&b);
		q=q/__gcd(p,q);
		while(__gcd(q,b)!=1)
			{
				q=q/__gcd(q,b);
				b=__gcd(b,q);
			}
		if(q==1)
			printf("Finite\n");
		else
			printf("Infinite\n"); 
	}
}