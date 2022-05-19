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
ios_base::sync_with_stdio(false);
        cin.tie(0);
        int N;
        cin >> N;

        int input1, input2;

        for(register int i = 0; i < N; i++){
                cin >> input1 >> input2;


                if(input1 > input2){
                        cout << ((input1*input2) / gcd(input1, input2)) << '\n';
                        continue;
                }
                else{
                        cout << ((input1*input2) / gcd(input2, input1)) << '\n';
                        continue;
                }

        }

        return 0;

}
