//qn1 assignment1
//code:
#include<bits/stdc++.h>
using namespace std;
int mex(unordered_set <int> set)
{
		int mex=0;
		while(set.find(mex)!=set.end())
			mex++;
		return mex;
}	
int main()
{
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		int n;
		scanf("%d%*c",&n);
		char arr[n][n];
		for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
						scanf("%c",&arr[i][j]);
						scanf("%*c");
			}
		int grundy[n][n]; 
		if(arr[0][0]!='X')
			grundy[0][0]=0;
		else
			grundy[0][0]=-1;
		for(int i=1;i<n;i++)
			{
				if(arr[i][0]=='X')
					grundy[i][0]=-1;
				else if(grundy[i-1][0]==0)
						grundy[i][0]=1;
				else
					grundy[i][0]=0;
			}
			for(int j=1 ;j<n;j++)
			{	
				if(arr[0][j]=='X')
					grundy[0][j]=-1;
				else if(grundy[0][j-1]==0)
						grundy[0][j]=1;
				else
					grundy[0][j]=0;
			}
			for(int i=1;i<n;i++)
				for(int j=1;j<n;j++)
					{
						if(arr[i][j]=='X')
							{
								grundy[i][j]=-1;
								continue;
							}
						else 
						{
							unordered_set<int> set;
							if(grundy[i-1][j]!=-1)
							set.insert(grundy[i-1][j]);
							if(grundy[i][j-1]!=-1)
							set.insert(grundy[i][j-1]);
							if(grundy[i-1][j-1]!=-1)
							set.insert(grundy[i-1][j-1]);
							grundy[i][j]=mex(set);
						}
					}

				int c=0;
				for (int i = 0; i < n; ++i)
					for (int j = 0; j < n; ++j)
						if(arr[i][j]=='K')
							c=c^grundy[i][j];
			int win = 0;
        for (int i = 0; i < n; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
            	//printf("win=%d i=%d j=%d c=%d arr[i][j]=%c\n",win,i,j,c,arr[i][j]);
            	if(i==0&&j==0)
            		continue;
            	if(i<1)
                	{
                		if (arr[i][j] == 'K')
                    		win += (arr[i][j-1] != 'X' && (c^grundy[i][j]^grundy[i][j-1]) == 0);
                    }
                else if(j<1)
                	     {
                	       	if (arr[i][j] == 'K') 
                    			win += (arr[i-1][j] != 'X' && (c^grundy[i][j]^grundy[i-1][j]) == 0);
                    	}
            	else
            	{
            		//printf("win=%d i=%d j=%d c=%d\n",win,i,j,c);
	            	if (arr[i][j] == 'K') 
	            	{

	                    win += (arr[i][j-1] != 'X' && (c^grundy[i][j]^grundy[i][j-1]) == 0);
	                    win += (arr[i-1][j] != 'X' && (c^grundy[i][j]^grundy[i-1][j]) == 0);
	                    win += (arr[i-1][j-1] != 'X' && (c^grundy[i][j]^grundy[i-1][j-1]) == 0);
	                    	
	            	}
	            }
	        }
	    }
	        				if(c==0)
					printf("LOSE\n");
				else
					printf("WIN %d\n",win);
	}	
} 
