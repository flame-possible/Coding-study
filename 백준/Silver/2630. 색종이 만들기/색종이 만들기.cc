#include <iostream>

using namespace std;

int input[130][130] = {0,};
int num_0 = 0;
int num_1 = 0;

void divide(int start1, int last1, int start2, int last2){




        register int pan = 0;
/*
        if(start1 == start2 && last1 == last2){

                for(register int i = start1; i <= last1; i++){
                        for(register int j = start1; j <= last1; j++){
                                if(input[start1][last1] != input[i][j]){
                                        pan = 1;
                                        break;
                                }
                        }
                        if(pan & 1){
                                break;
                        }
                }

        }
        else{
*/
                for(register int i = start2; i <= last2; i++){
                        for(register int j = start1; j <= last1; j++){
                                if(input[start2][start1] != input[i][j]){
                                        pan = 1;
                                        break;
                                }
                        }
                        if(pan & 1){
                                break;
                        }
                }

//      }

        if(pan & 1){
                int mid1 = (start1 + last1) / 2;
                int mid2 = (start2 + last2) / 2;

                divide(start1, mid1, start2, mid2);
                divide(mid1+1, last1, mid2+1, last2);

                divide(mid1+1, last1, start2, mid2);
                divide(start1, mid1, mid2+1, last2);

        }
        else{
                if(input[start2][last1] == 0){
                        num_0++;
                }
                else{
                        num_1++;
                }
        }
        return;

}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int N;

        cin >> N;

        for(register int i = 1; i <= N; i++){
                for(register int j = 1; j <= N; j++){
                        cin >> input[i][j];
                }
        }

        divide(1, N, 1, N);

        cout << num_0 << '\n';
        cout << num_1 << '\n';

        return 0;

}
