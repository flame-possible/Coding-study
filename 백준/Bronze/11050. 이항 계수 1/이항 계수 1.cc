#include <iostream>

using namespace std;

int factorial(int a){

        if(a == 0){
                return 1;
        }

        if(a == 1){
                return 1;
        }
        else{
                return a * factorial(a-1);
        }

}

int main(){

        int N, K;

        cin >> N >> K;
        cout << (factorial(N) / (factorial(K) * factorial(N - K))) << '\n';

        return 0;

}
