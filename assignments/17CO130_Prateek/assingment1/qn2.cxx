//Assignment1 qn1:GAMSTICK
//Submission Link:https://www.codechef.com/submit/complete/18639378
//code:
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
int main()
{
	ull t;
	scanf("%llu",&t);
	while(t--)
	{
		ull N,y1,y2;
		scanf("%llu",&N);
		int x1,x2;
		scanf("%d%llu%d%llu",&x1,&y1,&x2,&y2);
		if(y1==y2)
			printf("Draw\n");
		else if(x1==x2)
		{
			if(y1>y2)
			{
				y1=N+1-y1;
				y2=N+1-y2;
			}
			//printf("%llu %llu\n",y1,y2);
			ull pos=(y1+y2)/2;
		if (pos==N-pos ) {
			printf("Draw\n");
		}
		else if (pos>N-pos )
			printf("Miron\n");
		else
			printf("Slava\n");
		}
		else
		{
			if(y1>y2)
			{
				y1=N+1-y1;
				y2=N+1-y2;
			}
			if(y2-y1==1)
				{
					if(y1>N-y1)
						printf("Miron\n");
					else
						printf("Draw\n");
				}
			else
			{
					ull toGo = y2 - y1 - 2LL;
					y1 += ( toGo + 1 ) / 2;
					y2 -= toGo / 2;
					if ( y1 > N - y1) {
						printf("Miron\n");
					}
					else if ( y1 + 1 < N - y1 - 1 ) {
						printf("Slava\n");
					}
					else
						printf("Draw\n");
			}
		}
	}
}