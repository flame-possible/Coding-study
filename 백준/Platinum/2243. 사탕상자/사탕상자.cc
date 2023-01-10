#include <bits/stdc++.h>

using namespace std;

int input[5000001];

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int n;

        cin >> n;

        int index_start = 1;

        while(index_start < 1000000){
                index_start <<= 1;
        }

        int temp_1, temp_2, temp_3;

        for(register int i = 0; i < n; i++){

                cin >> temp_1;

                if(temp_1 & 1){

                        cin >> temp_2;

                        int temp = 1;
                        int temp_left = temp * 2;
                        int temp_right = (temp * 2) + 1;

//                      cout << input[temp] << '\n';
//                      cout << input[temp] << ' ' << input[temp_left] << ' ' << input[temp_right] << '\n';

                        while((input[temp_left] != 0) || (input[temp_right] != 0)){

//                              cout << input[temp] << ' ' << input[temp_left] << ' ' << input[temp_right] << '\n';
                                if(input[temp_left] != 0){

                                        if(input[temp_left] < temp_2){
                                                temp_2 -= input[temp_left];

                                                temp = temp_right;
                                        }
                                        else{
                                                temp = temp_left;
                                        }

                                }

                                else if(input[temp_left] == 0){

                                        temp = temp_right;

                                }


                                temp_left = temp * 2;
                                temp_right = (temp * 2) + 1;

                        }

                        int ans = temp;

                        input[temp] -= 1;
                        while(temp/2){
                                input[temp/2] -= 1;
                                temp /= 2;
                        }

                        cout << ans - index_start + 1 << '\n';

                }

                else{

                        cin >> temp_2 >> temp_3;

                        int leaf_start = index_start + temp_2 - 1;

                        input[leaf_start] += temp_3;

                        int temp = leaf_start;

                        while(temp/2){
                                input[temp/2] += temp_3;
                                temp /= 2;
                        }

                }

        }

        return 0;

}
