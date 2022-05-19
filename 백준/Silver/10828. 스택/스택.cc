#include <iostream>

using namespace std;

int stack[10001] = {0,};
int nodecnt = 0;

int strcmp(char *a, char *b){

        int i = 0;

        while(a[i]){
                if(a[i] != b[i]){
                        break;
                }
                i++;
        }
        return a[i] - b[i];

}

int main(){
ios_base::sync_with_stdio(false);
        cin.tie(0);
        int N;

        cin >> N;

        char sel_1[10] = "push";
        char sel_2[10] = "pop";
        char sel_3[10] = "size";
        char sel_4[10] = "empty";
        char sel_5[10] = "top";


        for(register int i = 0; i < N; i++){

                char input1[10];

                cin >> input1;

                if(!strcmp(input1, sel_1)){
                        int temp;
                        cin >> temp;
                        stack[nodecnt++] = temp;
                        continue;
                }
                else if(!strcmp(input1, sel_2)){
                        if(nodecnt != 0){
                                cout << stack[nodecnt - 1] << '\n';
                                nodecnt--;
                                continue;
                        }
                        else{
                                cout << "-1" << '\n';
                                continue;
                        }
                }
                else if(!strcmp(input1, sel_3)){
                        cout << nodecnt << '\n';
                        continue;
                }
                else if(!strcmp(input1, sel_4)){
                        if(nodecnt != 0){
                                cout << "0" << '\n';
                                continue;
                        }
                        else{
                                cout << "1" << '\n';
                                continue;
                        }
                }
                else if(!strcmp(input1, sel_5)){
                        if(nodecnt == 0){
                                cout << "-1" << '\n';
                                continue;
                        }
                        else{
                                cout << stack[nodecnt - 1] << '\n';
                                continue;
                        }
                }

        }

        return 0;

}
