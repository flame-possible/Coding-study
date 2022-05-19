#include <iostream>
#include <string>

using namespace std;

int queue[2000001] = {0,};
int front = 0;
int last = 0;

int main(){

        cin.tie(NULL);
        ios_base::sync_with_stdio(false);

        int N;

        cin >> N;

        for(register int i = 0; i < N; i++){

                string input;

                cin >> input;


                if(input == "push"){
                        int temp;
                        cin >> temp;

                        queue[last++] = temp;

                }

                else if(input == "pop"){
                        if(front == last){
                                cout << "-1\n";
                                continue;
                        }
                        cout << queue[front++] << '\n';
                }

                else if(input == "size"){
                        cout << last - front << '\n';
                }

                else if(input == "empty"){
                        if(front == last){
                                cout << '1' << '\n';
                        }
                        else{
                                cout << '0' << '\n';
                        }
                }

                else if(input == "front"){
                        if(front == last){
                                cout << "-1\n";
                                continue;
                        }
                        cout << queue[front] << '\n';

                }
                else{
                        if(front == last){
                                cout << "-1\n";
                                continue;
                        }
                        cout << queue[last-1] << '\n';
                }

        }

        return 0;

}
