/* https://www.codechef.com/problems/GAMSTICK */
/* https://www.codechef.com/viewsolution/18560183 */

#include <bits/stdc++.h>

using namespace std;

#define ll long long 

int main()
{
  ll t;
  cin >> t;
  while (t--)
  {
    ll n, x1,y1,x2,y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    if (y1 == y2) 
    {
        printf("Draw\n"); continue;
    }
    if (y1 > y2) y1 = n + 1 - y1, y2 = n + 1 - y2;
    if (x1 != x2)
    {
      if (y1 > n/2) 
          printf("Miron\n");
      else if (y2 <= (n+1)/2)
      {
          if(y2-y1==1)   
              printf("Draw\n"); 
          else
              printf("Slava\n");
      }
      else
      {
        if (y2 - (n/2 + 1 - y1) > n/2 + 1) 
            printf("Miron\n");
        else if (y1 + y2 - (n+1)/2 < (n+1)/2 - 1)
            printf("Slava\n");
        else
            printf("Draw\n");
      }
    }
    else
    {
      ll x = y1 + (y2-y1-1)/2 + (y2-y1-1) % 2; 
      if ( x > n - x) 
          printf("Miron\n");
      else if(x < n - x)
          printf("Slava\n");
      else
          printf("Draw\n"); 
    }
  }
}   
