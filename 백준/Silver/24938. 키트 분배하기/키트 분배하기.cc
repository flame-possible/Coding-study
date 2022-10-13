#include <iostream>

using namespace std;

int input[200001] = {0,};

int main(){


        int N;
        cin >> N;

        long long total = 0;

        for(register int i = 0; i < N; i++){

                cin >> input[i];
                total += input[i];
        }

        int cnt = 0;

        long long room_kit = total / N;

        long long result = 0;

        while(cnt != N){

                if(input[cnt] < room_kit){
                        int need_kit = room_kit - input[cnt];
                        int temp_cnt = cnt+1;
                        for(register int i = temp_cnt; i < N; i++){
                                int temp = input[i] - room_kit;
                                if(temp > 0){
                                        if(temp >= need_kit){
                                                input[i] -= need_kit;
                                                result += (need_kit * (i - cnt));
                                                input[temp_cnt-1] = room_kit;
                                                break;
                                        }
                                        else{
                                                input[i] -= temp;
                                                result += (temp * (i - cnt));
                                                input[temp_cnt-1] += temp;
                                        }
                                }
                        }
                        cnt++;
                }
                else if(input[cnt] > room_kit){
                        int over_kit = input[cnt] - room_kit;
                        int temp_cnt = cnt+1;
                        for(register int i = temp_cnt; i < N; i++){
                                int temp = room_kit - input[i];
                                if(temp > 0){
                                        if(temp >= over_kit){
                                                input[i] += over_kit;
                                                result += (over_kit * (i - cnt));
                                                input[temp_cnt-1] = room_kit;
                                                break;
                                        }
                                        else{
                                                input[i] += temp;
                                                result += (temp * (i - cnt));
                                                input[temp_cnt-1] -= temp;
                                        }
                                }
                        }
                        cnt++;
                }
                else{
                        cnt++;
                }

        }

        cout << result << '\n';

        return 0;
}
