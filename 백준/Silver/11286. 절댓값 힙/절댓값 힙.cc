#include <iostream>

using namespace std;

struct Heap{

        int node[100001];
        int size;

};

Heap heap;

void insert_heap(int n){

        register int i = ++heap.size;

        int temp = n;
        if(temp < 0){
                temp = -temp;
        }

        int parent_temp = heap.node[i/2];
        if(parent_temp < 0) parent_temp = -parent_temp;

        while((i != 1) && (temp <= parent_temp)){

                if(temp == parent_temp){
                        if(n > heap.node[i/2]){
                                break;
                        }
                }

                heap.node[i] = heap.node[i/2];

                i /= 2;

                parent_temp = heap.node[i/2];
                if(parent_temp < 0) parent_temp = -parent_temp;


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

                if(child > heap.size) break;

                int child_temp = heap.node[child];
                if(child_temp < 0) child_temp = -child_temp;

                int child_plus = heap.node[child + 1];
                if(child_plus < 0) child_plus = -child_plus;

                int parent_temp = heap.node[parent];
                if(parent_temp < 0) parent_temp = -parent_temp;

                if(child + 1 <= heap.size && child_temp > child_plus){
                        child++;
                        child_temp = child_plus;
                }

                else if(child + 1 <= heap.size && child_temp == child_plus){
                        if(heap.node[child] > heap.node[child+1]){
                                child++;
                                child_temp = child_plus;
                        }
                }

                if(child_temp > parent_temp) break;

                else if(child_temp == parent_temp){
                        if(heap.node[child] >= heap.node[parent]){
                                break;
                        }
                }

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
