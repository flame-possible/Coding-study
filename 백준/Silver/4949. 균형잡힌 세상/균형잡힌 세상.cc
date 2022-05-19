#include <iostream>
#include <stdio.h>

using namespace std;

char stack[101];
int nodecnt;

int main(){

        while(1){

                char input[101] = {0,};
                //scanf(" %s", input);
                register int len = 0;

                for(register int i = 0; i < 101; i++){

                        scanf("%c", &input[i]);
                        if(input[i] == '.'){
                                len = i;
                                break;
                        }

                }
                char temp;
                scanf("%c", &temp);
                if(input[0] == '.'){
                        break;
                }

                nodecnt = 0;


                register int result = 0;

                for(register int i = 0; i < len; i++){
                        if(input[i] == '(' || input[i] == '['){
                                stack[nodecnt++] = input[i];
                        }
                        else if(input[i] == ')' || input[i] == ']'){
                                if(nodecnt == 0){
                                        result = 1;
                                        break;
                                }
                                if(')' == input[i]){
                                        if(stack[nodecnt-1] == '('){
                                                nodecnt--;
                                        }
                                        else{
                                                result = 1;
                                                break;
                                        }
                                }
                                else{
                                        if(stack[nodecnt-1] == '['){
                                                nodecnt--;
                                        }
                                        else{
                                                result = 1;
                                                break;
                                        }
                                }
                        }
                }

                if(result == 1 || nodecnt != 0){
                        cout << "no\n";
                }
                else{
                        cout << "yes\n";
                }

        }

        return 0;

}
