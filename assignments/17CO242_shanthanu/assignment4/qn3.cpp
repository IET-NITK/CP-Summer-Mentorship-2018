/*
output:
1
2
3
5
7
*/

#include <iostream>
#include <vector>
using namespace std;
//min-heap
#define NO_ELEMENT 1e9

class priority_queue{
	private:
			vector<int> heap = vector<int>(1, NO_ELEMENT);
			bool in_heap(int pos);
			void swap_pos(int pos1, int pos2);
			void heapify_up(int n);
			void heapify_down(int n);
	public:
			void insert(int element);
			int extract_min();
};

bool priority_queue::in_heap(int pos) {
	if(pos > 0 && pos < heap.size()) {
		return true;
	}
	return false;
}

void priority_queue::swap_pos(int pos1, int pos2) {
	swap(heap[pos1], heap[pos2]);
}

void priority_queue::heapify_up(int n) {
	if(in_heap(n) && in_heap(n/2)) {
		int child = heap[n], parent = heap[n/2];
		if(child < parent) {
			swap_pos(n,n/2);
			heapify_up(n/2);
		}
	}
}

void priority_queue::heapify_down(int n) {
	if(!in_heap(2*n+1)) {
		heap.push_back(NO_ELEMENT);
	}
	if(in_heap(n) && in_heap(2*n)) {
		int parent = heap[n], child1 = heap[2*n], child2 = heap[2*n+1];
		if(parent > child1 || parent > child2) {
			if(child1 < child2) {
				swap_pos(n, 2*n);
				heapify_down(2*n);
			}
			else {
				swap_pos(n, 2*n+1);
				heapify_down(2*n+1);
			}
		}
	}
	if(heap[heap.size()-1] == NO_ELEMENT) {
		heap.erase(heap.end()-1);
	}
}

void priority_queue::insert(int element) {
	heap.push_back(element);
	heapify_up(heap.size()-1);
}

int priority_queue::extract_min() {
	if(heap.size() == 1) {
		return NO_ELEMENT;
	}
	int element = heap[1];
	heap[1] = heap[heap.size()-1];
	heap.erase(heap.end()-1);
	heapify_down(1);
	return element;
}



int main() {
	priority_queue hash;
	hash.insert(5);
	hash.insert(7);
	hash.insert(3);
	hash.insert(2);
	hash.insert(1);
	cout<<hash.extract_min()<<endl;
	cout<<hash.extract_min()<<endl;
	cout<<hash.extract_min()<<endl;
	cout<<hash.extract_min()<<endl;
	cout<<hash.extract_min()<<endl;
	return 0;
}