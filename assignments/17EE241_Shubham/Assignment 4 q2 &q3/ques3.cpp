#include<bits/stdc++.h>

using namespace std;
 
void swap(int *x, int *y);
 
class MinHeap
{
    int *harr; // pointer to array of elements in heap
    int n; // maximum possible size of heap
    int heap_size; // Current number of elements in heap
public:
    MinHeap(int n);
    void MinHeapify(int );
    int parent(int i) { return (i-1)/2; }
    int left(int i) { return (2*i + 1); }
    int right(int i) { return (2*i + 2); }
    int extractMin(); 
    void insertKey(int k);
};
 

MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    n = cap;
    harr = new int[cap];
}
 

void MinHeap::insertKey(int k)
{
    if (heap_size == n)
    {
        cout << "\n Could not insertKey\n";
        return;
    }
 
    // First insert the new key at the end
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;
 
    // Fix the min heap property if it is violated
    while (i != 0 && harr[parent(i)] > harr[i])
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}

int MinHeap::extractMin()
{
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }
 
    // Store the minimum value, and remove it from heap
    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MinHeapify(0);
 
    return root;
}
 
 
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}
 
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
 
int main()
{	
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    int c,x=1;
	int val,val2;
while(x)
{
cout<<"enter choice";
cout<<"\n 1.insertion \n 2.min extraction:\n";
cin>>c;
switch(c)
{
	case 1: cout<<"Enter the element to be inserted:";
			cin>>val;
			h.insertKey(val);
			 break;
	
	case 2: cout<<"minimum extracted:";
				cout << h.extractMin() << " ";
				break;
}

cout<<"one more time?(1/0)";
cin>>x;
}			
	return 0;
			
}


