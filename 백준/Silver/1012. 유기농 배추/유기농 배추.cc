#include <iostream>
#include <string.h>

using namespace std;

int input[51][51];

int check[51][51];

void DFS(int y, int x){

        if((check[y][x] & 1) || !(input[y][x] & 1)){
                return;
        }

        check[y][x] = 1;

        DFS(y-1, x);
        DFS(y+1, x);
        DFS(y, x-1);
        DFS(y, x+1);

        return;
}

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        register int T;

        cin >> T;

        for(register int q = 0; q < T; q++){

                int M, N, K;

                memset(input, 0, sizeof(input));
                memset(check, 0, sizeof(check));

                cin >> M >> N >> K;

                int temp_1, temp_2;

                for(register int i = 0; i < K; i++){
                        cin >> temp_1 >> temp_2;
                        input[temp_1+1][temp_2+1] = 1;
                }


                register int group = 0;

                for(register int i = 1; i <= M; i++){
                        for(register int j = 1; j <= N; j++){
                                if(!(check[i][j] & 1)){
                                        if(input[i][j] & 1){
                                                group++;
                                                DFS(i, j);
                                        }
                                        else{
                                                check[i][j] = 1;
                                        }
                                }
                        }
                }
                cout << group << '\n';

        }

        return 0;

}
