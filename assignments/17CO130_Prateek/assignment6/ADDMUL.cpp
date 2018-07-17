//submission link:https://www.codechef.com/viewsolution/19129019
//code:
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 1000000
#define M 1000000007
ll arr[MAX];
ll tree[MAX];
vector <pair< ll,ll> > lazy(MAX,make_pair(0,1));
void print_lazy(ll node,ll a , ll b)
{
	printf("[%llu,%llu]:(%llu,%llu) ",a,b,lazy[node].first,lazy[node].second);
	if(a==b)
		return;
	print_lazy(node*2,a,(a+b)/2);
	print_lazy(node*2+1,(a+b)/2+1,b);
}

void print_tree(ll node,ll a,ll b)
{
	if(a==b)
	{
		cout<<tree[node]<<" ";
		return;
	}
	print_tree(node*2,a,(a+b)/2);
	print_tree(node*2+1,(a+b)/2+1,b);
}

void build_tree(ll node,ll a,ll b)
{
	//cout<<"here";
	if(a==b)
	{
		tree[node]=arr[a];
		return;
	}
	build_tree(node*2,a,(a+b)/2);
	build_tree(node*2+1,(a+b)/2+1,b);
	tree[node]=(tree[node*2]%M+tree[node*2+1]%M)%M;
}
void f_lazy(ll node,ll a,ll b)
{
	if(lazy[node].first!=0||lazy[node].second!=1)
	{
		tree[node]=(((tree[node]%M)*(lazy[node].second%M))%M+((lazy[node].first%M)*(b-a+1)%M)%M)%M;
		if(a!=b)
		{
			lazy[node*2].first=(((lazy[node].second%M)*(lazy[node*2].first%M))%M+lazy[node].first%M)%M;
			lazy[node*2].second=((lazy[node*2].second%M)*(lazy[node].second%M))%M;
			lazy[node*2+1].first=(((lazy[node].second%M)*(lazy[node*2+1].first%M))%M+lazy[node].first%M)%M;
			lazy[node*2+1].second=((lazy[node*2+1].second%M)*(lazy[node].second%M))%M;
		}
		lazy[node].first=0;
		lazy[node].second=1;
	}
}
ll query(ll node,ll a,ll b,ll l ,ll r)
{
	
	if(l>b||r<a)
		return 0;
	f_lazy(node,a,b);
	if(a>=l&&r>=b)
		return tree[node]%M;

	return (query(node*2,a,(a+b)/2,l,r)%M+query(node*2+1,(a+b)/2+1,b,l,r)%M)%M;
}

void update(ll node,ll a,ll b,ll l , ll r,ll value ,ll temp)
{
	if(lazy[node].first!=0||lazy[node].second!=1)
	{
		tree[node]=((tree[node]%M)*(lazy[node].second%M))%M+((lazy[node].first%M)*(b-a+1)%M)%M;
		lazy[node].first=0,lazy[node].second=1;
	}
	if(l>b||r<a)
		return;
	if(a>=l&&b<=r)
	{
		if(temp==1)
			lazy[node].first=(lazy[node].first%M+value%M%M);

		if(temp==2)
			{
				lazy[node].first=((lazy[node].first%M)*(value%M))%M;
				lazy[node].second=((lazy[node].second%M)*(value%M))%M;
			}
		f_lazy(node,a,b);
		return;
	}
	update( node*2, a,(a+b)/2,l,r,value,temp);
	update( node*2+1,(a+b)/2+1,b,l,r,value,temp);
	tree[node]=(tree[node*2]%M+tree[node*2+1]%M)%M;
}

int main()
{
	ll N,Q;
	cin>>N>>Q;
	for(ll i=0;i<N;++i)
		cin>>arr[i];
	build_tree(1,0,N-1);
	while(Q--)
	{
		ll t,x,y;
		cin>>t>>x>>y;
		if(t==1)
		{
			ll v;
			cin>>v;
			update(1,0,N-1,x-1,y-1,v,t);
			//print_tree(1,0,N-1);	
			//cout<<endl;
			//print_lazy(1,0,N-1);
			//cout<<endl;
		}
		if(t==2)
		{
			ll v;
			cin>>v;
			update(1,0,N-1,x-1,y-1,v,t);
			//print_tree(1,0,N-1);
			//cout<<endl;
			//print_lazy(1,0,N-1);
			//cout<<endl;
		}
		if(t==3)
		{
			ll v;
			cin>>v;
			//update(1,0,N-1,x-1,y-1,v,t);
			//print_tree(1,0,N-1);
			//cout<<endl;
		}
		if(t==4)
		{
			cout<<query(1,0,N-1,x-1,y-1)<<endl;
			//print_lazy(1,0,N-1);
			//cout<<endl;
		}
	}
}