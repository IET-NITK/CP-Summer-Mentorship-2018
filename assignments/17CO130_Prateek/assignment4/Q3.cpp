//Assignment4 qn3 , Implementing max heap
//code:
#include<bits/stdc++.h>
using namespace std;
int largest;
int heap_size;
void print_heap(int*  arr)
{
		for (int i = 1; i <=heap_size; ++i)
		cout<<arr[i]<<" ";
		cout<<"\n";	
}
void max_heapify (int* arr, int i)
    {
        int left = 2*i;                
        int right = 2*i +1;        
        if(left<= heap_size and arr[left] > arr[i] )
              largest = left;
        else
             largest = i;
        if(right <= heap_size and arr[right] > arr[largest] )
            largest = right;
        if(largest != i )
        {
            swap (arr[i] , arr[largest]);
            max_heapify (arr, largest);
        }
     }
int extract_max(int *arr)
{
	if(heap_size==0)
		return -1;
	int m=arr[1];
	swap(arr[1],arr[heap_size]);
	heap_size--;
	max_heapify(arr,1);
	return m;
}
int* insert(int* arr,int element)
{
	heap_size++;
	arr=(int *)realloc(arr,sizeof(int)*(heap_size+1));
	arr[heap_size]=element;
	int i=heap_size;
	while(i>1&&arr[i]>arr[i/2])
	{
		swap(arr[i],arr[i/2]);
		i=i/2;
	}
	return arr;
}
int main()
{
	heap_size=7;
	int *arr=(int *)malloc(sizeof(int)*(heap_size+1));
	arr[1]=1;
	arr[2]=9;
	arr[3]=4;
	arr[4]=3;
	arr[5]=7;
	arr[6]=2;
	arr[7]=0;	
	for(int i=heap_size;i>=1;--i)
		max_heapify(arr,i);			//Building heap
	print_heap(arr);// Output:9 7 4 3 1 2 0
	int m=extract_max(arr);
	if(m==0)
		cout<<"heap is  already empty"<<endl;//Output:9
	else
	cout<<m<<endl;
	print_heap(arr);//Output:7 3 4 0 1 2
	arr=insert(arr,10);
	print_heap(arr);//Ouutput: 10 3 7 0 1 2 4
}