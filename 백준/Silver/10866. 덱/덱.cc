#include <iostream>
#include <string>

using namespace std;

int deck[20000] = {0,};

int start_1 = 0;
int end_1 = 1;

int size(){

        int result;

        if(start_1 < end_1){
                result = end_1 - start_1 - 1;
        }
        else{
                result = end_1 + (19999 - start_1);
        }

        return result;

}

int main(){
ios_base::sync_with_stdio(false);
        cin.tie(0);
        int N;

        cin >> N;

        while(N--){

                string input;
                cin >> input;

                if(input == "push_front"){
                        int temp;
                        cin >> temp;
                        deck[start_1] = temp;
                        start_1--;
                        start_1 += 20000;
                        start_1 %= 20000;
                        /*if(start_1 < 0){
                                start_1 = 19999;
                        }*/
                }
                else if(input == "push_back"){
                        int temp;
                        cin >> temp;
                        deck[end_1] = temp;
                        end_1++;
                        end_1 %= 20000;
                }
                else if(input == "pop_front"){
                        if(size() != 0){
                                start_1++;
                                start_1 %= 20000;

                                cout << deck[start_1] << '\n';
                        }
                        else{
                                cout << "-1\n";
                        }
                }
                else if(input == "pop_back"){
                        if(size() != 0){
                                end_1 = ((end_1 - 1) + 20000) % 20000;
                                /*if(end_1 < 0){
                                        end_1 = 19999;
                                }*/
                                cout << deck[end_1] << '\n';
                        }
                        else{
                                cout << "-1\n";
                        }
                }
                else if(input == "size"){
                        cout << size() << '\n';
                }

                else if(input == "empty"){

                        if(size() != 0){
                                cout << "0\n";
                        }
                        else{
                                cout << "1\n";
                        }

                }
                else if(input == "front"){
                        if(size() != 0){
                                int temp = start_1;
                                temp++;
                                temp %= 20000;

                                cout << deck[temp] << '\n';
                        }
                        else{
                                cout << "-1\n";
                        }
                }
                else{
                        if(size() != 0){
                                int temp = end_1;
                                temp = ((temp - 1) + 20000) % 20000;
                                /*if(temp < 0){
                                        temp = 19999;
                                }*/
                                cout << deck[temp] << '\n';
                        }
                        else{
                                cout << "-1\n";
                        }
                }


        }

        return 0;

}
