#include <bits/stdc++.h>

using namespace std;

int input[51][51];

struct Home{

        int y, x, dis;

};

struct Shop{

        int y, x;

};

Home home[101];
int home_cnt;

Shop shop[14];
int shop_cnt;
int visited[14];

int result;

int N, M;

void Track(int dep, int chicken){

        if(dep == M){


                for(register int j = 0; j < home_cnt; j++) home[j].dis = 100000;

                for(register int j = 0; j < home_cnt; j++){

                        for(register int i = 0; i < shop_cnt; i++){

                                if(visited[i]){
                                        int temp = abs(home[j].y - shop[i].y) + abs(home[j].x - shop[i].x);

                                        if(home[j].dis > temp) home[j].dis = temp;
                                }
                        }
                }




                int temp = 0;

                for(register int i = 0; i < home_cnt; i++){
                        temp += home[i].dis;
                }

                if(result > temp) result = temp;

                return;

        }

        for(register int i = chicken; i < shop_cnt; i++){

                if(!visited[i]){
                        visited[i] = 1;
                        Track(dep + 1, i + 1);
                        visited[i] = 0;
                }
        }

        return;

}

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        cin >> N >> M;

        result = 100000000;

        for(register int i = 0; i < N; i++){
                for(register int j = 0; j < N; j++){

                        cin >> input[i][j];

                        if(input[i][j] & 1){
                                home[home_cnt].y = i;
                                home[home_cnt++].x = j;
                        }

                        else if(input[i][j] & 2){
                                shop[shop_cnt].y = i;
                                shop[shop_cnt++].x = j;
                        }

                }
        }


        Track(0, 0);

        cout << result << '\n';

        return 0;

}
