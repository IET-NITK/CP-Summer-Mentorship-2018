#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int T;
	scanf("%lld",&T);
	while(T--)
	{
		unsigned long long int N,y1,y2;
		int x1,x2;
		scanf("%llu%d%llu%d%llu",&N,&x1,&y1,&x2,&y2);
		if(y2>y1)
		{
			if((N-y2)>(y1-1))
				printf("Slava\n");
			else if((N-y2)<(y1-1))
				printf("Miron\n");
			else
				printf("Draw\n");
		}
		else if(y2<y1)
		{
			if((N-y1)>(y2-1))
				printf("Slava\n");
			else if((N-y1)<(y2-1))
				printf("Miron\n");
			else
				printf("Draw\n");
		}
		else
			printf("Draw\n");
	}
}
		
		
