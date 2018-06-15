//https://www.codechef.com/LTIME52/problems/C00K0FF/
//https://www.codechef.com/viewsolution/18550367
//code:
# include <iostream>

using namespace std;

int main(){
 

int t;

cin>>t;

while(t--){

int n;

cin>>n;

int i;

int c=0,e=0,s=0,em=0,m=0,mh=0,h=0;

for(i=1;i<=n;i++){

char str[100];

cin>>str;

if(str[0]=='c')

c=1;

else if(str[0]=='s')

s=1;

else if(str[0]=='e'&&str[4]=='-')

em=1;

else if(str[0]=='e')

e=1;

else if(str[0]=='m'&&str[6]=='-')

mh=1;

else if(str[0]=='m')

m=1;

else if(str[0]=='h')

h=1;

}

if(c==1&&s==1&&e==1&&(em==1||m==1)&&(mh==1||h==1))

cout<<"Yes\n";

else

cout<<"No\n";

}

return 0;
 

} 