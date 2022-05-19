#include <iostream>

using namespace std;

int main(){

        char input[51] = {0,};

        cin >> input;

        register int i = 0;

        register int result = 0;
        register int temp = 0;
        register int pos = 0;

        register bool operand = false;

        while(input[i] != 0){


                if(input[i] == '+' || input[i] == '-'){

                        if(operand == false){
                                pos = 0;
                                result += temp;
                                temp = 0;
                        }
                        else{
                                pos = 0;
                                result -= temp;
                                temp = 0;
                        }

                        if(input[i] == '-'){

                                operand = true;

                        }
                }

                else{
                        if(pos > 0){
                                temp *= 10;
                                temp += input[i] - '0';
                        }
                        else{
                                temp += input[i] - '0';
                        }
                        pos++;
                }
                i++;

                if(input[i] == 0){
                        if(operand == false){
                                result += temp;
                        }
                        else{
                                result -= temp;
                        }
                }
        }

        cout << result << '\n';

        return 0;

}
