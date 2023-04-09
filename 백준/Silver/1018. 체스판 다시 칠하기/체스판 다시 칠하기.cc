#include <bits/stdc++.h>

using namespace std;

char input[51][51];
int N, M;

string w_start[8] = {

        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
};

string b_start[8] = {

        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
};

int w_check(int col, int row){

        int count = 0;
        int w_col = 0;
        int w_row = 0;

        for(register int i = col; i < col + 8; i++){
                w_row = 0;
                for(register int j = row; j < row + 8; j++){
                        if(input[i][j] != w_start[w_col][w_row++]) count++;
                }
                w_col++;
        }

        return count;

}

int b_check(int col, int row){

        int count = 0;
        int b_col = 0;
        int b_row = 0;

        for(register int i = col; i < col + 8; i++){
                b_row = 0;
                for(register int j = row; j < row + 8; j++){
                        if(input[i][j] != b_start[b_col][b_row++]) count++;
                }
                b_col++;
        }

        return count;

}

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        cin >> N >> M;

        for(register int i = 0; i < N; i++){
                for(register int j = 0; j < M; j++){
                        cin >> input[i][j];
                }
        }

        int result = 70;

        for(register int i = 0; i < N - 7; i++){

                for(register int j = 0; j < M - 7; j++){

                        int temp = min(w_check(i, j), b_check(i, j));

                        if(result > temp) result = temp;

                }

        }


        cout << result << '\n';

        return 0;

}
