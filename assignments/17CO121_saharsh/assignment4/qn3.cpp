#include<bits/stdc++.h>
using namespace std;

 typedef long long ll;
 #define pb push_back
 #define f(i,a,n) for(ll i=0;i<n;i++)
 #define mod 1000000007
 #define mp make_pair

 int swap(int *x , int *y)
 {
   int temp;
   temp=*x;
   *x=*y;
   *y=temp;
 }

class minheap
{
  public:

      int capacity;
      int heap_size;
      int arr[100];

    minheap (int c);
    void proclaim_up(int element);
    int parent(int i)
    {
      return (i-1)/2;
    }
    void heapify();
    void adjust(int i);

};


minheap::minheap(int c)
{

  capacity=c;
  heap_size=0;

}

void minheap::heapify()
{
  int root=arr[0];
  arr[0]=arr[heap_size-1];
  heap_size--;
  adjust(0);
}

void minheap::adjust(int i)
{
  int l = i*2 + 1;
  int r = i*2 + 2;
  int s = i;
  if( l < heap_size && arr[l] < arr[s] )
  s=l;
  if( r < heap_size && arr[r] < arr[s] )
  s=r;
  if(s!=i)
  {
    swap(&arr[i],&arr[s]);
    i=s;
    adjust(i);
  }
}

void minheap::proclaim_up(int element)
{
  if(heap_size==capacity)
  {
    cout<<"OVERFLOW\n";
    return ;
  }
  heap_size++;
  int i=heap_size-1;
  arr[i]=element;
  while( i != 0 && arr[i] < arr[parent(i)] )
  {

    swap(&arr[i],&arr[parent(i)]);
    i=parent(i);
  }
}

 int main()
 {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  //insert
  minheap h(15);
  h.proclaim_up(1);
  h.proclaim_up(21);
  h.proclaim_up(12);
  h.proclaim_up(5);
  h.proclaim_up(9);
  h.proclaim_up(8);
  h.proclaim_up(6);
  h.proclaim_up(4);
  h.proclaim_up(10);
  h.proclaim_up(2);
  h.proclaim_up(7);
  h.proclaim_up(3);
  h.heapify();
  f(i,0,h.heap_size) cout<<h.arr[i]<<"\t";

 }

 //https://www.geeksforgeeks.org/binary-heap/
