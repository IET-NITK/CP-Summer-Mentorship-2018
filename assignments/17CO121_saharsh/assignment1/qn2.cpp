#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int main()
{
    long int t,n;
    cin>>t;
    string temp;
    for(int i=0;i<t;i++)
    {
      cin>>n;
      vector<int> v={0,0,0,0,0};
      vector<int>::iterator it=v.begin();

      for(int j=0;j<n;j++)
      {
        cin>>temp;
        if(temp=="cakewalk") (*(it))++;
        if(temp=="simple") (*(it+1))++;
        if(temp=="easy") (*(it+2))++;
        if(temp=="easy-medium"||temp=="medium") (*(it+3))++;
        if(temp=="medium-hard"||temp=="hard") (*(it+4))++;
      }
        if((*(it))>=1&&(*(it+1))>=1&&(*(it+2))>=1&&(*(it+3))>=1&&(*(it+4))>=1)
        cout<<"\nYes";
        else
        cout<<"\nNo";
      }
}
