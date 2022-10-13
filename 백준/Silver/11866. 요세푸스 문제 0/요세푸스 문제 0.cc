#include <iostream>

using namespace std;

int queue1[1000001] = {0,};
int result[1000001] = {0,};

int start1 = 0;
int end1 = 0;

void push(int in){

        queue1[end1] = in;
        end1++;
        end1 %= 1000001;

}

int pop(){

        int ans = queue1[start1];
        start1++;
        start1 %= 1000001;
        return ans;

}

int main(){

        int N;
        int K;

        cin >> N >> K;

        for(register int i = 0; i < N; i++){

                queue1[i] = i+1;

        }

        end1 = N;

        int count = 1;

        int temp = 1;

        while(count < N+1){

                if(temp == K){
                        result[count++] = pop();
                        temp = 1;
                }
                else{
                        push(pop());
                        temp++;
                }

        }

        cout << '<';
        for(register int i = 1; i < N; i++){
                cout << result[i] << ", ";
        }
        cout << result[N] << '>' << '\n';

        return 0;

}
