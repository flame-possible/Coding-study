#include <iostream>

using namespace std;

int gcd(int a, int b){

        int temp;
        while(b){

                temp = a % b;
                a = b;
                b = temp;

        }

        return a;
}

int main(){

        int N;
        cin >> N;

        int input[100] = {0,};

        for(register int i = 0; i < N; i++){

                cin >> input[i];

        }

        int cri = input[0] * 2;
        for(register int i = 1; i < N; i++){
                int temp;
                int pre = input[i] * 2;
                if(cri > pre){
                        temp = gcd(cri, pre);
                        cout << (cri / temp) << '/' << (pre / temp) << '\n';
                        continue;
                }
                else{
                        temp = gcd(pre, cri);
                        cout << (cri / temp) << '/' << (pre / temp) << '\n';
                }

        }


        return 0;

}
