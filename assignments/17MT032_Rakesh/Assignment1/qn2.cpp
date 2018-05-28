/* https://www.codechef.com/problems/C00K0FF */
/* https://www.codechef.com/viewsolution/18556130 */

#include <bits/stdc++.h>

using namespace std;
#define ll long long 

int main()
{
    ll t,n;
    string d;
    cin >> t;
    while(t--)
    {
        cin >> n ;
        map < string , ll > M;
        for(int i=0;i<n;++i)
        {
            cin >> d;
            M[d]++;
        }
        if(M["cakewalk"]&&M["simple"]&&M["easy"]&&(M["easy-medium"]||M["medium"])&&(M["medium-hard"]||M["hard"]))
            printf("Yes\n");
        else
            printf("No\n");
    }
    
}
