#include <iostream>

using namespace std;

unsigned long long A, B, C;

unsigned long long mul(unsigned long long in){

        if(in == 1){
                return A % C;
        }

        unsigned long long temp = mul(in/2) % C;

        if(in % 2 == 0){
                return temp * temp % C;
        }
        else{
                return temp * temp % C * A % C;
        }

}

int main(){

        cin >> A >> B >> C;

        cout << mul(B) << '\n';

        return 0;
}
