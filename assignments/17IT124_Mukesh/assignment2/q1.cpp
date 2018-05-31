//Q:https://www.hackerrank.com/contests/university-codesprint-3/challenges/bobs-game
//A:https://www.hackerrank.com/contests/university-codesprint-3/challenges/bobs-game/submissions/code/1307678001


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int mex(set<int>& s) {
    int m = -1;
    while(s.find(++m) != s.end());
    return m;
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        char board[n][n];
        vector<vector <int> >grundy(n,vector<int>(n,100));
        vector<int> i1;
        vector<int> j1;
        grundy[0][0]=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>board[i][j];
                if(board[i][j]=='K')
                {
                    i1.push_back(i);
                    j1.push_back(j);
                }
                if(board[i][j]=='X')
                {
                    grundy[i][j]=10000;
                }
            }
        }

        for(int i=1;i<n;i++)
        {
            if(grundy[i][0]==100)
            {
                if(grundy[i-1][0]==0)
                    grundy[i][0]=1;
                else
                    grundy[i][0]=0;
            }
        }
        for(int i=1;i<n;i++)
        {
            if(grundy[0][i]==100)
            {
                if(grundy[0][i-1]==0)
                    grundy[0][i]=1;
                else
                    grundy[0][i]=0;
            }
        }
        for(int i=1;i<n;i++)
            for(int j=1;j<n;j++)
                if(grundy[i][j]==100)
                {
                    set<int> s;
                    s.insert(grundy[i-1][j]);
                    s.insert(grundy[i-1][j-1]);
                    s.insert(grundy[i][j-1]);
                    grundy[i][j] = mex(s);
                }


    long ns=0;
    for(int i=0;i!=i1.size();i++)
        ns^=grundy[i1[i]][j1[i]];
    //cout<<ns<<endl;
    if(ns==0)
        cout<<"LOSE"<<endl;
    else
    {
       cout<<"WIN ";
       long count=0;
       for(int l=0;l<i1.size();l++)
       {
           ns^=grundy[i1[l]][j1[l]];
           int i=i1[l];
           int j=j1[l];
           if(i==0 && j==0)
               continue;
           long temp=ns;
           if(i1[l]!=0 && j1[l]!=0)
           {
               if(board[i-1][j]!='X')
               {
                    temp^=grundy[i-1][j];
                    if(temp==0)
                        count++;
                    temp=ns;
               }
               if(board[i-1][j-1]!='X')
               {
                  temp^=grundy[i-1][j-1];
                  if(temp==0)
                       count++;
                  temp=ns;
               }
               if(board[i][j-1]!='X')
               {
                  temp^=grundy[i][j-1];
                   if(temp==0)
                     count++;
                   temp=ns;
               }
           }
           if(i==0)
           {
               if(board[i][j-1]!='X')
               {
                  temp^=grundy[i][j-1];
                   if(temp==0)
                     count++;
                   temp=ns;
               }
           }
           if(j==0)
           {
               if(board[i-1][j]!='X')
               {
                  temp^=grundy[i-1][j];
                   if(temp==0)
                     count++;
                   temp=ns;
               }
           }
           ns^=grundy[i][j];
       }
        cout<<count<<endl;

    }
    }
    return 0;
}

