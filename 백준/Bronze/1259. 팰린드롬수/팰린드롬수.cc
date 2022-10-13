#include <iostream>
#include <stdio.h>
//#include <string.h>

using namespace std;

int main(){

        //ios_base::sync_with_stdio(false);
        //cin.tie(0);


        while(1){

                char input[10];

                cin >> input;

                //cin.ignore(256, '\n');
                //cin.getline(input, 10);
                /*
                char temp;
                cin >> temp;
                */

                //scanf("%s", input);
                //getchar();


                if(input[0] == '0'){
                        break;
                }

                register int end = 0;
                while(input[end] != 0){
                        end++;
                }
                end--;
                register int start = 0;

                register int result = 0;

                while(start < end){
                        if(input[start] != input[end]){
                                result = 1;
                                break;
                        }
                        start++;
                        end--;
                }
                if(result == 1){
                        cout << "no\n";
                }
                else{
                        cout << "yes\n";
                }


        }

        return 0;
}
