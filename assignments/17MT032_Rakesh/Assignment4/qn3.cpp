/* OUTPUT:-
1
2
3
5
7
10
*/
#include <bits/stdc++.h>
using namespace std;
class p_q{
	private:
			vector<int> heap = vector<int>(1,(int)1e9);
			bool in_heap(int pos);
			void swap_pos(int pos1, int pos2);
			void heapify_up(int n);
			void heapify_down(int n);
	public:
			void insert(int element);
			int extract_min();
};

bool p_q::in_heap(int pos) {
	if(pos > 0 && pos < heap.size()) {
		return true;
	}
	return false;
}

void p_q::swap_pos(int pos1, int pos2) {
	swap(heap[pos1], heap[pos2]);
}

void p_q::heapify_up(int n) {
	if(in_heap(n) && in_heap(n/2)) {
		int child = heap[n], parent = heap[n/2];
		if(child < parent) {
			swap_pos(n,n/2);
			heapify_up(n/2);
		}
	}
}

void p_q::heapify_down(int n) {
	if(!in_heap(2*n+1)) {
		heap.push_back(1e9);
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
	if(heap[heap.size()-1] == 1e9) {
		heap.erase(heap.end()-1);
	}
}

void p_q::insert(int element) {
	heap.push_back(element);
	heapify_up(heap.size()-1);
}

int p_q::extract_min() {
	if(heap.size() == 1) {
		return 1e9;
	}
	int element = heap[1];
	heap[1] = heap[heap.size()-1];
	heap.erase(heap.end()-1);
	heapify_down(1);
	return element;
}

int main() {
	p_q q;
	q.insert(5);
	q.insert(7);
	q.insert(3);
	q.insert(2);
	q.insert(1);
	q.insert(10);
	cout<<q.extract_min()<<endl;
	cout<<q.extract_min()<<endl;
	cout<<q.extract_min()<<endl;
	cout<<q.extract_min()<<endl;
	cout<<q.extract_min()<<endl;
	cout<<q.extract_min()<<endl;
	return 0;
}
