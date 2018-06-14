//CODE
//MAXHEAP

#include<bits/stdc++.h>
using namespace std;
int heap[1000];
int n,num,size=0;
void swap(int &a,int &b)
{
   int temp;
   temp=a;
   a=b;
   b=temp;
}
void insert_heap(int pos)
{
   if((pos-1)/2 >=0)
   {
    if(heap[pos]>heap[((pos-1)/2)])
        {swap(heap[pos],heap[((pos-1)/2)]);
        insert_heap((pos-1)/2);
        }}
}
int extract_max()
{
    size--;
    return heap[0];
}
int heapify()
{
    heap[0]=heap[size];
    for(int i=size-1;i>=0;--i)
    {
        insert_heap(i);
    }
}
int main()
{


    cout<<"NUMBER OF ELEMENTS :";
    cin>>n;
    cout<<endl;
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;++i)
    {cin>>num;
    heap[size]=num;
    insert_heap(size);
    size++;
    }
    int inp;
    cout<<"Enter number of Maximum elements required"<<endl;
    cin>>inp;
    for(int j=0;j<inp;++j)
    {

    cout<<"Extract max element"<<endl;
    cout<<extract_max()<<endl;
    heapify();
    cout<<"New heap is"<<endl;
    for(int i=0;i<size;++i)
        cout<<heap[i]<<" ";
        cout<<endl;}
}
