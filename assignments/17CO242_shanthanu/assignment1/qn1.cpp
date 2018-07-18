//https://www.codechef.com/problems/GAMSTICK
// solution link : https://www.codechef.com/viewsolution/19252809

#include <bits/stdc++.h>
using namespace std;
void solve(long long n,long long x1,long long y1,long long x2,long long y2)
{
    if(x1==x2)
    {
      long long x = y1+(y2-y1-1)/2+(y2-y1-1)%2;
      if (x>n-x)
          cout<<"Miron"<<endl;
      else if(x<n-x)
          cout<<"Slava"<<endl;
      else
          cout<<"Draw"<<endl;
    }
    else{
        if (y1>n/2)
            cout<<"Miron"<<endl;
        else if (y2<=(n+1)/2)
        {
            if(y2-y1 == 1)
                cout<<"Draw"<<endl;
            else
                cout<<"Slava"<<endl;
        }
        else
        {
            if (y2-(n/2+1-y1) > n/2+1)
                cout<<"Miron"<<endl;
            else if (y1 + y2 - (n+1)/2 < (n+1)/2 - 1)
                cout<<"Slava"<<endl;
            else
                cout<<"Draw"<<endl;
        }
    }
}
int main()
{
  long long t;
  cin >> t;
  while (t--)
  {
    long long n, x1,y1,x2,y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    if (y1 == y2)
    {
        cout<<"Draw"<<endl;
        continue;
    }
 
    if (y1 > y2){
        y1 = n + 1 - y1;
        y2 = n + 1 - y2;
    }
    solve(n,x1,y1,x2,y2);
  }
 
} 