//max heap
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void max_heapify (int Arr[ ], int i, int N)
{
    int left = 2*i;                  //left child
    int right = 2*i +1,largest;           //right child
    if(left<= N and Arr[left] > Arr[i] )
          largest = left;
    else
         largest = i;
    if(right <= N and Arr[right] > Arr[largest] )
        largest = right;
    if(largest != i )
    {
        swap (Arr[i] , Arr[largest]);
        max_heapify (Arr, largest,N);
    } 
}
void build_maxheap (int Arr[ ],int N)
{
    for(int i = N/2 ; i >= 1 ; i-- )
    {
        max_heapify (Arr, i,7) ;
    }
}
int main(){
int Arr[8],i;
for(i=1;i<7;i++)
Arr[i]=10*(9-i);//already a max heap
//insert 90
Arr[7]=90;//intially at leaf
build_maxheap(Arr,7);
cout<<"after inserting element"<<endl;
for(i=1;i<8;i++)
cout<<Arr[i]<<endl;
//now removing max and placing last leaf at its position
Arr[1]=Arr[7];
build_maxheap(Arr,6);
cout<<"after extracting max"<<endl;
for(i=1;i<7;i++)
cout<<Arr[i]<<endl;}

/*output:
after inserting element
90
70
80
50
40
30
60
after extracting max
80
70
60
50
40
30*/


