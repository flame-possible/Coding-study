#include <iostream>

using namespace std;

int queue[500001];
int start = 0;
int last = 0;
int size_queue = 0;

void push(int in){

        queue[last] = in;

        last++;
        last %= 500000;

        size_queue++;
}

int pop(){

        int result = queue[start];

        start++;
        start %= 500000;

        size_queue--;

        return result;
}

int main(){

        int N;

        cin >> N;

        for(register int i = 0; i < N; i++){

                queue[i] = i+1;

        }

        size_queue = N;

        last = N;
        last %= 500000;

        while(size_queue != 1){
                pop();
                push(pop());

        }

        cout << queue[start] << '\n';


        return 0;

}
