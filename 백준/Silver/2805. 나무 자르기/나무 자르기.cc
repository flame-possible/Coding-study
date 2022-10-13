#include <iostream>

using namespace std;

int input[1000001] = {0,};

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int N, M;

        int max = 0;

        cin >> N >> M;

        for(register int i = 0; i < N; i++){
                cin >> input[i];
                if(max < input[i]){
                        max = input[i];
                }
        }

        int left = 1;
        int right = max;

        int mid = 0;

        long long temp = 0;
        int pan = 0;
        int result = 0;

        while(left <= right){
                temp = 0;
                mid = (left + right) / 2;
//              cout << mid << '\n';
                for(register int i = 0; i < N; i++){
                        long long temp_val = input[i] - mid;
                        if(temp_val > 0){
                                temp += temp_val;
                        }
                }
//              cout << temp << '\n';
                if(pan & 1){
                        if(temp > M){
                                left = mid + 1;
                                result = mid;
                        }
                        else if(temp < M){
                                right = mid - 1;
                        }
                        else{
                                left = mid + 1;
                                result = mid;
                        }
                }

                else{
                        if(temp > M){
                                left = mid + 1;
                                pan = 1;
                                result = mid;
                        }
                        else if(temp < M){
                                right = mid - 1;
                        }
                        else{
                                left = mid + 1;
                                pan = 1;
                                result = mid;
                        }
                }

        }

        cout << result << '\n';

        return 0;
}
