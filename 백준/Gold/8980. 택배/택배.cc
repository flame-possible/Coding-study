#include <iostream>
#include <bits/stdc++.h>

int village_info[2001][2001];
int truck_info[2001];
int last_vil;
int N;

using namespace std;

void last_village(int cur){

        for(register int i = N; i > cur; i--){
                if(truck_info[i] != 0){
                        last_vil = i;
                        break;
                }
        }

}

int main(){

        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        int result = 0;
        int cur_box = 0;
        int truck_capacity = 0;

        int C, M;

        cin >> N >> C;


        cin >> M;

        int input_start, input_end, input_num;

        for(register int i = 0; i < M; i++){

                cin >> input_start >> input_end >> input_num;

                village_info[input_start][input_end] = input_num;

        }


        for(register int i = 1; i <= N; i++){

/*              cout << truck_capacity << '\n';

                for(register int j = 1; j <= N; j++){
                        cout << truck_info[j] << ' ';
                }
                cout << '\n';
*/
                if(i != 1){
                        result += truck_info[i];
                        truck_capacity -= truck_info[i];
                        last_village(i);
                }
/*
                cout << "Village num " << i << '\n';
                cout << "Result " << result << '\n';
*/
                for(register int j = i + 1; j <= N; j++){

                        //cout << "every village " << j << "\n";

                        if(village_info[i][j] != 0){
                                if(truck_capacity < C){

                                        int temp = village_info[i][j];

                                        if(temp >= C - truck_capacity){
                                                temp = C - truck_capacity;
                                        }
                                        village_info[i][j] -= temp;

                                        truck_capacity += temp;
                                        truck_info[j] += temp;
                                        last_village(i);

                                }

                                if(j < last_vil){

                                        if(village_info[i][j] > truck_info[last_vil]){

                                                int temp = village_info[i][j];

                                                if(truck_capacity < C){



                                                }


                                                while(temp > 0 && j != last_vil){

                                                        if(temp > truck_info[last_vil]){

                                                                truck_info[j] += truck_info[last_vil];
                                                                temp -= truck_info[last_vil];
                                                                truck_info[last_vil] = 0;
                                                                last_village(i);
                                                        }

                                                        else{
                                                                truck_info[last_vil] -= temp;
                                                                truck_info[j] += temp;
                                                                temp = 0;
                                                        }

                                                }

                                        }

                                        else{

                                                truck_info[last_vil] -= village_info[i][j];
                                                truck_info[j] += village_info[i][j];

                                                //last_village(i);

                                        }

                                }
/*
                                cout << "Check village " << j << '\n';
                                cout << truck_capacity << '\n';

                                for(register int k = 1; k <= N; k++){
                                        cout << truck_info[k] << ' ';
                                }
                                cout << '\n';
*/

                        }



                }

                last_village(i);

        }

        cout << result << '\n';


        return 0;

}
