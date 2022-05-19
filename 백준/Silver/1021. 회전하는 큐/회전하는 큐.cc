#include <iostream>

using namespace std;

int queue[100] = {0,};

int start_1 = 0;
int end_1 = 1;

int pop_front(){

        start_1++;
        start_1 %= 100;

        return queue[start_1];

}

int pop_back(){

        end_1 = ((end_1 - 1) + 100) % 100;

        return queue[end_1];

}

void push_back(int in){

        queue[end_1] = in;

        end_1++;
        end_1 %= 100;

}

void push_front(int in){

        queue[start_1] = in;

        start_1 = ((start_1 - 1) + 100) % 100;

}

int size(){

        if(start_1 < end_1){
                return end_1 - start_1 - 1;
        }
        else{
                return (99 - start_1) + end_1;
        }

}

int main(){

        int N, M;

        cin >> N >> M;

        for(register int i = 1; i <= N; i++){

                queue[i] = i;

        }

        end_1 = N+1;

        int com[51];
        for(register int i = 0; i < M; i++){
                cin >> com[i];
        }

        int count_l = 0;
        int count_r = 0;

        int count = 0;

        int result = 0;

        while(1){

                if(size() == 1) break;

                if(count == M){
                        break;
                }
                int temp = (start_1 + 1) % 100;

                int temp_cnt = 0;

                while(1){
                        if(queue[temp] == com[count]){
                                break;
                        }
                        temp = (temp + 1) % 100;
                        temp_cnt++;
                }
                if(temp_cnt <= size()/2){
                        for(int i = 0; i < temp_cnt; i++){
                                push_back(pop_front());
                                result++;
                        }
                        pop_front();
                }
                else{
                        for(int i = 0; i < size() - temp_cnt; i++){
                                push_front(pop_back());
                                result++;
                        }
                        pop_front();
                }
                count++;

        }

        cout << result << '\n';
        return 0;

}
