#include <bits/stdc++.h>

using namespace std;

int N;
int result;

void DFS(int input[][21], int num){

        if(num == 5){

                int temp = 0;

                for(register int i = 0; i < N; i++){
                        for(register int j = 0; j < N; j++){
                                if(input[i][j] > result){
                                        result = input[i][j];
                                }
                        }
                }

                return;

        }

        int temp[21][21] = {0,};
        int check[21] = {0,};
        int cnt = 0;

        for(register int i = 0; i < N; i++){
                for(register int j = 0; j < N; j++){
                        temp[i][j] = input[i][j];
                }
        }

        // right
        for(register int i = 0; i < N; i++){

                for(register int k = 0; k < N; k++){
                        for(register int j = N-2; j >= 0; j--){
                                if(temp[i][j+1]){
                                        if(temp[i][j+1] == temp[i][j] && !check[j+1] && !check[j]){
                                                temp[i][j+1] += temp[i][j];
                                                temp[i][j] = 0;
                                                check[j+1] = 1;
                                                check[j] = 0;
                                        }
                                }

                                else{
                                        if(temp[i][j]){
                                                temp[i][j+1] = temp[i][j];
                                                temp[i][j] = 0;

                                                if(check[j]){
                                                        check[j+1] = 1;
                                                        check[j] = 0;
                                                }
                                        }

                                }
                        }
                }


                for(register int j = 0; j <= N; j++){
                        check[j] = 0;
                }

        }

        DFS(temp, num+1);


        for(register int i = 0; i < N; i++){
                for(register int j = 0; j < N; j++){
                        temp[i][j] = input[i][j];
                }
        }

        // left
        for(register int i = 0; i < N; i++){

                for(register int k = 0; k < N; k++){
                        for(register int j = 1; j < N; j++){
                                if(temp[i][j-1]){
                                        if(temp[i][j-1] == temp[i][j] && !check[j-1] && !check[j]){
                                                temp[i][j-1] += temp[i][j];
                                                temp[i][j] = 0;
                                                check[j-1] = 1;
                                                check[j] = 0;
                                        }
                                }

                                else{

                                        if(temp[i][j]){
                                                temp[i][j-1] = temp[i][j];
                                                temp[i][j] = 0;

                                                if(check[j]){
                                                        check[j-1] = 1;
                                                        check[j] = 0;
                                                }
                                        }

                                }
                        }
                }

                for(register int j = 0; j <= N; j++){
                        check[j] = 0;
                }

        }


        DFS(temp, num+1);


        for(register int i = 0; i < N; i++){
                for(register int j = 0; j < N; j++){
                        temp[i][j] = input[i][j];
                }
        }

        // Top

        for(register int j = 0; j < N; j++){

                for(register int k = 0; k < N; k++){

                        for(register int i = 1; i < N; i++){

                                if(temp[i-1][j]){
                                        if(temp[i-1][j] == temp[i][j] && !check[i-1] && !check[i]){
                                                temp[i-1][j] += temp[i][j];
                                                temp[i][j] = 0;
                                                check[i-1] = 1;
                                                check[i] = 0;
                                        }
                                }

                                else{

                                        if(temp[i][j]){
                                                temp[i-1][j] = temp[i][j];
                                                temp[i][j] = 0;

                                                if(check[i]){
                                                        check[i-1] = 1;
                                                        check[i] = 0;
                                                }
                                        }

                                }

                        }
                }
                for(register int i = 0; i <= N; i++){
                        check[i] = 0;
                }
        }

        DFS(temp, num+1);


        for(register int i = 0; i < N; i++){
                for(register int j = 0; j < N; j++){
                        temp[i][j] = input[i][j];
                }
        }

        // Bottom

        for(register int j = 0; j < N; j++){

                for(register int k = 0; k < N; k++){

                        for(register int i = N-2; i >= 0; i--){

                                if(temp[i+1][j]){
                                        if(temp[i+1][j] == temp[i][j] && !check[i+1] && !check[i]){
                                                temp[i+1][j] += temp[i][j];
                                                temp[i][j] = 0;
                                                check[i+1] = 1;
                                                check[i] = 0;
                                        }
                                }

                                else{
                                        if(temp[i][j]){
                                                temp[i+1][j] = temp[i][j];
                                                temp[i][j] = 0;

                                                if(check[i]){
                                                        check[i+1] = 1;
                                                        check[i] = 0;
                                                }
                                        }

                                }

                        }

                }

                for(register int i = 0; i <= N; i++){
                        check[i] = 0;
                }
        }

        DFS(temp, num+1);

        return;

}

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        cin >> N;

        int input[21][21] = {0,};

        for(register int i = 0; i < N; i++){

                for(register int j = 0; j < N; j++){
                        cin >> input[i][j];
                }

        }

        DFS(input, 0);

        cout << result << '\n';

        return 0;

}
