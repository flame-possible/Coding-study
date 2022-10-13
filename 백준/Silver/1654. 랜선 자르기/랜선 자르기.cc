#include <iostream>

using namespace std;

int input[10001] ={0,};

int main(){
        ios_base::sync_with_stdio(false); 
        cin.tie(0);


        int K, N;

        int min = 2147483647;
        int max = 0;

        cin >> K >> N;

        for(register int i = 0; i < K; i++){
                cin >> input[i];
                if(min > input[i]){
                        min = input[i];
                }
                if(max < input[i]){
                        max = input[i];
                }
        }

        long long left = 1;
        long long right = max;

        long long mid;

        int temp_result = 0;

        int result = 0;

        int pan = 0;

        while(left <= right){
                temp_result = 0;
                mid = (left + right) / 2;
//              cout << mid << '\n';
                for(register int i = 0; i < K; i++){
                        temp_result += input[i]/mid;
                }
//              cout << temp_result << ' ' << N << '\n';
                if(pan & 1){
                        if(temp_result > N){
                                left = mid+1;
                                result = mid;
                        }
                        else if(temp_result < N){
                                right = mid-1;
                        }
                        else{
                                left = mid+1;
                                result = mid;
                        }
                }
                else{
                        if(temp_result == N){
                                pan = 1;
                                result = mid;
                        }
                        else if(temp_result > N){
                                left = mid+1;
                                result = mid;
                        }
                        else{
                                right = mid-1;
                        }
                }


        }

        cout << result << '\n';

        return 0;
}
