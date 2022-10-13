#include <iostream>

using namespace std;

struct Heap{

	int node[100001];
	int size;

};

Heap heap;

void insert_heap(int n){

	register int i = ++heap.size;

	while((i != 1) && (n > heap.node[i/2])){

		heap.node[i] = heap.node[i/2];

		i /= 2;

	}

	heap.node[i] = n;

}

int delete_heap(){

	if(heap.size == 0) return 0;

	int result = heap.node[1];
	heap.node[1] = heap.node[heap.size];
	heap.size--;

	int parent = 1;
	int child;

	while(1){

		child = parent * 2;
		if(child + 1 <= heap.size && heap.node[child] < heap.node[child + 1]){
			child++;
		}
		if(child > heap.size || heap.node[child] <= heap.node[parent]) break;

		int temp = heap.node[parent];
		heap.node[parent] = heap.node[child];
		heap.node[child] = temp;

		parent = child;

	}

	return result;

}

int main(){

	ios_base::sync_with_stdio(false); 
	cin.tie(0);

	int N;
	cin >> N;

	heap.size = 0;

	for(register int i = 0 ; i < N; i++){
		int temp;
		cin >> temp;

		if(temp == 0){
			cout << delete_heap() << '\n';
		}
		else{
			insert_heap(temp);
		}
		
	}

	return 0;

}