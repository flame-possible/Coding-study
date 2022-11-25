#include <bits/stdc++.h>

using namespace std;

char input[2001][2001];
int pan[2][2001][2001];


int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int N, M, K;

        cin >> N >> M >> K;

        for(register int i = 1; i <= N; i++){

                for(register int j = 1; j <= M; j++){
                        cin >> input[i][j];
                }

        }

        char start_w = 'W';
        char start_b = 'B';


        for(register int i = 1; i <= N; i++){

                if(start_w == 'W') start_w = 'B';
                else start_w = 'W';

                if(start_b == 'W') start_b = 'B';
                else start_b = 'W';


                for(register int j = 1; j <= M; j++){

                        if(j & 1){
                                if(start_w == 'W' && input[i][j] == 'B'){
                                        pan[0][i][j] = 1;
                                }

                                else if(start_w == 'B' && input[i][j] == 'W'){
                                        pan[0][i][j] = 1;
                                }


                                if(start_b == 'B' && input[i][j] == 'W'){
                                        pan[1][i][j] = 1;
                                }

                                else if(start_b == 'W' && input[i][j] == 'B'){
                                        pan[1][i][j] = 1;
                                }
                        }

                        else{

                                if(start_w == 'W' && input[i][j] == 'W'){
                                        pan[0][i][j] = 1;
                                }
                                else if(start_w == 'B' && input[i][j] == 'B'){
                                        pan[0][i][j] = 1;
                                }

                                if(start_b == 'B' && input[i][j] == 'B'){
                                        pan[1][i][j] = 1;
                                }
                                else if(start_b == 'W' && input[i][j] == 'W'){
                                        pan[1][i][j] = 1;
                                }


                        }


                }
        }
/*
        for(register int k = 0; k < 2; k++){
                for(register int i = 1; i <= N; i++){
                        for(register int j = 1; j <= M; j++){
                                cout << pan[k][i][j] << ' ';
                        }
                        cout << '\n';
                }
                cout << '\n';
        }

*/
        for(register int i = 1; i <= N; i++){

                int temp_1 = pan[0][i][1];
                int temp_2 = pan[1][i][1];

                for(register int j = 2; j <= M; j++){
                        temp_1 += pan[0][i][j];
                        temp_2 += pan[1][i][j];

                        pan[0][i][j] = temp_1;
                        pan[1][i][j] = temp_2;
                }
        }

        for(register int j = 1; j <= M; j++){

                int temp_1 = pan[0][1][j];
                int temp_2 = pan[1][1][j];

                for(register int i = 2; i <= N; i++){
                        temp_1 += pan[0][i][j];
                        temp_2 += pan[1][i][j];

                        pan[0][i][j] = temp_1;
                        pan[1][i][j] = temp_2;
                }

        }
/*
        for(register int k = 0; k < 2; k++){
                for(register int i = 1; i <= N; i++){
                        for(register int j = 1; j <= M; j++){
                                cout << pan[k][i][j] << ' ';
                        }
                        cout << '\n';
                }
                cout << '\n';
        }

*/

        int result = 5000000;

        for(register int y = 0; y <= N - K; y++){

                for(register int x = 0; x <= M - K; x++){

                        int temp_1 = pan[0][y + K][x + K] + pan[0][y][x] - pan[0][y][x + K] - pan[0][y + K][x];
                        int temp_2 = pan[1][y + K][x + K] + pan[1][y][x] - pan[1][y][x + K] - pan[1][y + K][x];

                        if(result > temp_1) result = temp_1;
                        if(result > temp_2) result = temp_2;

                }

        }

        cout << result << '\n';

        return 0;

}
