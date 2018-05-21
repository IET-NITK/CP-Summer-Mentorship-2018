//http://codeforces.com/problemset/problem/687/B/


//code:i am sending the code as each time it gets time out for me during submission.

#include <iostream>
using namespace std;
int GCD(int a , int b)
{
int temp;
if (a<b)
{
temp=a;
a=b;
b=temp;
}
if (b==0)
return a;
return GCD(b,a%b);
}
int LCM(int a,int b)
{
return a*b/GCD(a,b);
}
int main()
{
int n,k;
cin >> n >>k;
int t=1;
for(int i=0;i<n;i++)
{
int c;
cin >> c;
t=GCD(k,LCM(c,t));
}
if(t==k)
cout << "yes"<< endl;
else
cout <<"no"<< endl;
return 0;
}



