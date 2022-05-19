#include <iostream>

using namespace std;

long long search(long long mid, long long n){

        long long result = 0;

        for(register int i = 1; i < n + 1; i++){
                result += ((mid / i )> n) ? n : mid / i;
        }
        return result;

}

int main(){

        long long N, K;

        cin >> N >> K;

        long long left = 1;
        long long right = N * N;

        long long mid;

        while(left <= right){

                mid = (left + right) / 2;

                if(search(mid, N) >= K){
                        right = mid - 1;
                }
                else{
                        left = mid + 1;
                }

        }

        cout << left << '\n';

        return 0;

}
