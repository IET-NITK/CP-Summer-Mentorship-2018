//submission link:https://www.codechef.com/viewsolution/19100158
//code:
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll * make_seg_tree(ll t[],int n)
{
	for(ll i=n-1;i>0;--i)
		t[i]=t[2*i]+t[2*i+1];
	return t;
}

void print_arr(ll arr[],ll n)
{
	for(ll i=n;i<2*n;++i)
		cout<<arr[i]<<' ';
	cout<<endl;
}
ll query(ll t[],ll l,ll r,ll n)
{
	ll res=0;
	//cout<<r<<' '<<l<<' ';
	for(l+=n,r+=n;r>=l;l=l/2,r=r/2)
	{
		//cout<<r<<' '<<l<<endl;
		if(r%2==0)
			res+=t[r--];
		if(l%2!=0)
			res+=t[l++];
	}
	return res;
}
void modify(ll t[],ll index,ll value,ll n)
{
	index+=n;
	t[index]=value;
	while(index>0)
	{
		index/=2;
		t[index]=t[index*2+1]+t[index*2];
	}
}
int main()
{
	ll n;
	cin>>n;
	ll diff2[2*n],diff3[2*n],diff5[2*n];
	memset(diff2,0,sizeof(ll)*n*2);
	memset(diff3,0,sizeof(ll)*n*2);
	memset(diff5,0,sizeof(ll)*n*2);
	ll arr[n];
	for (ll i = 0; i < n; ++i)
			cin>>arr[i];

	ll M;
	cin>>M;
	while(M--)
	{
		ll t,l,r,p;
		cin>>t;
		//cout<<t<<" "<<M<<endl;
		if(t==1)
		{
			cin>>l>>r>>p;
			if(p==2)
			{
				modify(diff2,l-1,diff2[n+l-1]+1,n);
				if(r<n)
					modify(diff2,r,diff2[n+r]-1,n);
			}
			else if(p==3)
			{
				modify(diff3,l-1,diff3[n+l-1]+1,n);
				if(r<n)
					modify(diff3,r,diff3[n+r]-1,n);
			}
			else
			{
				modify(diff5,l-1,diff5[n+l-1]+1,n);
				if(r<n)
					modify(diff5,r,diff5[n+r]-1,n);
			}
			//print_arr(diff3,n);
		}
		else
		{
			ll l,d;
			cin>>l>>d;
			arr[l-1]=d;
			ll sum5_l,sum2_l,sum3_l,temp2,temp3,temp5;
			sum2_l=query(diff2,0,l-1,n);
			sum3_l=query(diff3,0,l-1,n);
			sum5_l=query(diff5,0,l-1,n);
			if(l!=n)
			{
			modify(diff2,l,sum2_l+diff2[l+n],n);
			modify(diff3,l,sum3_l+diff3[l+n],n);
			modify(diff5,l,sum5_l+diff5[l+n],n);
			}
			if(l!=1)
			{
				 sum2_l=query(diff2,0,l-2,n);
				 sum3_l=query(diff3,0,l-2,n);
				 sum5_l=query(diff5,0,l-2,n);
			}
			else
			{
				 sum2_l=0;
				 sum3_l=0;
				 sum5_l=0;
			}
			modify(diff2,l-1,-sum2_l,n);
			modify(diff3,l-1,-sum3_l,n);
			modify(diff5,l-1,-sum5_l,n);
			//print_arr(diff3,n);
		}
	}
	int t2=diff2[n],t3=diff3[n],t5=diff5[n];
	while(arr[0]%2==0&&t2--)
			arr[0]/=2;
		while(arr[0]%3==0&&t3--)
			arr[0]/=3;
		while(arr[0]%5==0&&t5--)
			arr[0]/=5;
		//cout<<10<<' '<<"diff2[0]="<<diff2[0]<<" "<<"diff3[0]="<<diff3[0]<<" "<<"diff5[0]="<<diff5[0]<<" ";
		cout<<arr[0]<<' ';//<<endl;
	for(ll i=n+1;i<2*n;++i)
	{
		//cout<<i<<' '<<"diff2[i]="<<diff2[i]<<" "<<"diff3[i]="<<diff3[i]<<" "<<"diff5[i]="<<diff5[i]<<" ";
		diff2[i]+=diff2[i-1];
		diff3[i]+=diff3[i-1];
		diff5[i]+=diff5[i-1];
		 t2=diff2[i],t3=diff3[i],t5=diff5[i];
		while(arr[i-n]%2==0&&t2--)
			arr[i-n]/=2;
		while(arr[i-n]%3==0&&t3--)
			arr[i-n]/=3;
		while(arr[i-n]%5==0&&t5--)
			arr[i-n]/=5;
		cout<<arr[i-n]<<" ";//<<endl;
	}
}