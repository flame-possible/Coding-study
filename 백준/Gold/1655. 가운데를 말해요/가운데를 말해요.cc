#include <iostream>

using namespace std;

struct Max_heap{

        int node[100001];
        int size;

};

struct Min_heap{

        int node[100001];
        int size;

};

Max_heap max_heap;
Min_heap min_heap;

int insert_max(int n){

        int i = ++max_heap.size;

        while((i != 1) && (n > max_heap.node[i/2])){

                max_heap.node[i] = max_heap.node[i/2];
                i /= 2;

        }

        max_heap.node[i] = n;

        return max_heap.node[1];

}

int insert_min(int n){

        int i = ++min_heap.size;

        while((i != 1) && (n < min_heap.node[i/2])){

                min_heap.node[i] = min_heap.node[i/2];
                i /= 2;

        }

        min_heap.node[i] = n;

        return min_heap.node[1];

}


int delete_max(){

        int result = max_heap.node[1];

        max_heap.node[1] = max_heap.node[max_heap.size--];

        int child = 2;
        int parent = 1;

        while(child <= max_heap.size){

                if((child < max_heap.size) && (max_heap.node[child] < max_heap.node[child+1])){
                        child++;
                }
                if(max_heap.node[child] <= max_heap.node[parent]) break;

                int temp = max_heap.node[child];
                max_heap.node[child] = max_heap.node[parent];
                max_heap.node[parent] = temp;

                parent = child;

                child *= 2;

        }

        return result;

}

int delete_min(){

        int result = min_heap.node[1];

        min_heap.node[1] = min_heap.node[min_heap.size--];

        int child = 2;
        int parent = 1;

        while(child <= min_heap.size){

                if((child < min_heap.size) && (min_heap.node[child] > min_heap.node[child+1])){
                        child++;
                }
                if(min_heap.node[child] >= min_heap.node[parent]) break;

                int temp = min_heap.node[child];
                min_heap.node[child] = min_heap.node[parent];
                min_heap.node[parent] = temp;

                parent = child;

                child *= 2;

        }

        return result;

}


int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);


        int N;

        cin >> N;

        int temp;

        for(register int i = 0; i < N; i++){
                cin >> temp;
                if(max_heap.size <= min_heap.size){
                        insert_max(temp);
                }
                else{
                        insert_min(temp);
                }
                if((max_heap.node[1] > min_heap.node[1]) && max_heap.size > 0 && min_heap.size > 0){
                        int max_a = max_heap.node[1];
                        int min_a = min_heap.node[1];

                        delete_min();
                        delete_max();
                        insert_max(min_a);
                        insert_min(max_a);
                }
/*
                for(register int j = 1; j <= max_heap.size; j++){
                        cout << max_heap.node[j] << ' ';
                }
                cout << '\n';
*/
                cout << max_heap.node[1] << '\n';

        }

        return 0;

}
