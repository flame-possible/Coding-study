#include <iostream>
#include <algorithm>

using namespace std;

int main(){

        int N, C;

        cin >> N >> C;

        int input[200001] = {0,};

        for(register int i = 0; i < N; i++){
                cin >> input[i];
        }

        sort(input, input+N);

        int left = 1;
        int right = input[N - 1] - input[0];
        int mid;

        int result = 0;

        while(left <= right){
                mid = (left + right) / 2;
                int num = 1;
                int previous = input[0];

                for(register int i = 1; i < N; i++){
                        if((input[i] - previous) >= mid){
                                num++;
                                previous = input[i];
                        }
                }

                if(num >= C){
                        left = mid + 1;
                        result = (result > mid) ? result : mid;
                }
                else{
                        right = mid - 1;
                }


        }

        cout << result << '\n';

        return 0;

}
