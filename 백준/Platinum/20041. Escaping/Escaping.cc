#include <bits/stdc++.h>

using namespace std;

long long int caps[500001][2];

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int N;

        cin >> N;

        for(register int i = 0; i < N; i++){
                cin >> caps[i][0] >> caps[i][1];
        }

        long long int in_x, in_y;

        cin >> in_x >> in_y;

        int count[4] = {0,};

        for(register int i = 0; i < N; i++){

            long long int temp_x = 0;
            long long int  temp_y = 0;

            if(caps[i][0] == in_x && caps[i][1] > in_y){
                    count[0] = 1;
            }
            if(caps[i][0] < in_x && caps[i][1] > in_y){
                    temp_x = in_x - caps[i][0];
                    temp_y = caps[i][1] - in_y;
                    if(temp_x <= temp_y){
                            count[0] = 1;
                    }
                    if(temp_x >= temp_y){
                            count[3] = 1;
                    }

            }
            if(caps[i][1] == in_y && caps[i][0] > in_x){
                    count[1] = 1;

            }
            if(caps[i][0] > in_x && caps[i][1] > in_y){
                    temp_x = caps[i][0] - in_x;
                    temp_y = caps[i][1] - in_y;

                    if(temp_x >= temp_y){
                            count[1] = 1;

                    }
                    if(temp_x <= temp_y){
                            count[0] = 1;
                    }

            }

            if(caps[i][0] == in_x && caps[i][1] < in_y){
                    count[2] = 1;
            }
            if(caps[i][0] > in_x && caps[i][1] < in_y){
                    temp_x = caps[i][0] - in_x;
                    temp_y = in_y - caps[i][1];
                    if(temp_x <= temp_y){
                            count[2] = 1;

                    }
                    if(temp_x >= temp_y){
                            count[1] = 1;
                    }

            }
            if(caps[i][1] == in_y && caps[i][0] < in_x){
                    count[3] = 1;

            }
            if(caps[i][0] < in_x && caps[i][1] < in_y){
                    temp_x = in_x - caps[i][0];
                    temp_y = in_y - caps[i][1];

                    if(temp_x >= temp_y){
                            count[3] = 1;

                    }
                    if(temp_x <= temp_y){
                            count[2] = 1;
                    }

            }


        }

        for(register int i = 0; i < 4; i++){
                if(count[i] == 0){
                        cout << "YES\n";
                        return 0;
                }
        }

        cout << "NO\n";

        return 0;

}