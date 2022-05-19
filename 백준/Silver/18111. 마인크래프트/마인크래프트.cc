#include <iostream>

using namespace std;

int main(){


        int N, M, B;

        cin >> N >> M >> B;

        int input[501][501] = {0,};

        for(register int i = 0; i < N; i++){
                for(register int j = 0; j < M; j++){
                        cin >> input[i][j];
                }
        }

        int time = 2e9;

        int height = 0;

        for(register int i = 0; i < 257; i++){

                int inven = 0;
                int remove = 0;

                for(register int j = 0; j < N; j++){
                        for(register int k = 0; k < M; k++){
                                int temp = input[j][k] - i;
                                if(temp < 0){
                                        inven -= temp;
                                }
                                else{
                                        remove += temp;
                                }
                        }

                }
                if(remove + B >= inven){
                        int temp_time = (remove * 2) + inven;
                        if(temp_time <= time){
                                time = temp_time;
                                height = i;
                        }
                }

        }

        cout << time << ' ' << height << '\n';


        return 0;
}
