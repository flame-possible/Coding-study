#include <iostream>

using namespace std;

int queue[1000] = {-1,};

int output[1000] = {-1,};

int start_1 = 0;
int end_1 = 0;

int start_2 = 0;
int end_2 = 0;

void push(int in, int pan){

        if(pan & 1){
                queue[end_1] = in;
                end_1++;
                end_1 %= 1000;
        }
        else{
                output[end_2] = in;
                end_2++;
                end_2 %= 1000;
        }

}

int pop(int pan){

        int result;

        if(pan & 1){
                result = queue[start_1];
                start_1++;
                start_1 %= 1000;

        }
        else{
                result = output[start_2];
                start_2++;
                start_2 %= 1000;
        }

        return result;

}


int main(){
ios_base::sync_with_stdio(false);
        cin.tie(0);
        int T;

        cin >> T;

        int result;

        while(T--){

                int N, M;

                cin >> N >> M;

                int infor[10] = {0,};

                int max = 0;

                for(register int i = 0; i < 1000; i++){
                        queue[i] = 0;
                        output[i] = -1;
                }

                for(register int i = 0; i < N; i++){
                        int temp;
                        cin >> temp;

                        infor[temp]++;

                        if(max < temp){
                                max = temp;
                        }

                        queue[i] = temp;
                        output[i] = i;
                }
                start_1 = 0;
                start_2 = 0;
                end_1 = N;
                end_2 = N;

                int count = 0;

                while(start_1 < end_1){

                        if(queue[start_1] != max){
                                push(pop(1), 1);
                                push(pop(2), 2);
                        }
                        else{
                                infor[max]--;
                                while(1){
                                        if(infor[max] == 0){
                                                max--;
                                        }
                                        else{
                                                break;
                                        }
                                }
                                pop(1);
                                count++;
                                result = pop(2);
                                if(result == M){
                                        cout << count << '\n';
                                        break;
                                }
                        }

                }

        }

        return 0;

}
