/*
Sample Output:

99 77 65 85 49 7 48 51 40 63
 Elements added to heap :
7 40 48 51 63 77 49 99 65 85
 Elements after Heapsort :
7 40 48 49 51 63 65 77 85 99


*/

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

#define INT_MAX 1e9
using namespace std;
class heap
{
    vector<int> heap_array;
    public:
        heap() {
            heap_array.push_back(INT_MAX);
        }

        void percolate_up(int data)
        {
            heap_array.push_back(data);
            int pos = heap_array.size()-1;
            while(pos/2 > 0)
            {
                int par_pos=pos/2;
                if(heap_array[pos]<heap_array[par_pos])
                {
                    int temp=heap_array[pos];
                    heap_array[pos]=heap_array[par_pos];
                    heap_array[par_pos]=temp;
                }
                pos=par_pos;
            }
        }
    void MinHeapify(int i)
    {
        int l = 2*i;
        int r = 2*i+1;
        int smallest = i;
        if (l < heap_array.size() && heap_array[l] < heap_array[i])
            smallest = l;
        if (r < heap_array.size() && heap_array[r] < heap_array[smallest])
            smallest = r;
        if (smallest != i)
        {
            int temp=heap_array[i];
            heap_array[i]=heap_array[smallest];
            heap_array[smallest]=temp;
            MinHeapify(smallest);
        }
    }

        int extractMin()
        {
            if(heap_array.size()==1)
                return INT_MAX;
            if (heap_array.size() == 2)
                return heap_array[1];

            int root = heap_array[1];
            heap_array[1] = heap_array[heap_array.size()-1];
            heap_array.pop_back();
            MinHeapify(1);
            return root;
        }

    void output()
    {
         for (int i = 1; i < 11; ++i) {
              cout<<heap_array[i]<<" ";
         }
    }
};
int main()
{
    heap h;
    srand(time(NULL));
    for(int i=0;i<10;i++){
        int ele=rand()%100;
        ele++;
        h.percolate_up(ele);
        cout<<ele<<" ";
    }
    cout<<"\n Elements added to heap"<<endl;
    h.output();
    cout<<"\n Elements after Heapsort : "<<endl;
    for(int i=1 ; i<11 ; i++){
        int ele=h.extractMin();
        cout<<ele<<" ";
    }


}
