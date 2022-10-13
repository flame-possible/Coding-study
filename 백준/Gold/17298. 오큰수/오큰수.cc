#include <iostream>

using namespace std;

int stack[1000001] = {0,};
int nodecnt = 0;

int main(){
ios_base::sync_with_stdio(false);
        cin.tie(0);
        int N;

        cin >> N;

        int input[1000001] = {0,};

        for(register int i = 0; i < N; i++){

                cin >> input[i];
        }

        int result[1000001] = {0,};

        for(register int i = N-1; i > -1; i--){

                while(nodecnt != 0 && input[i] >= stack[nodecnt-1]){
                        nodecnt--;
                }

                if(nodecnt == 0){
                        result[i] = -1;
                }
                else{
                        result[i] = stack[nodecnt-1];
                }

                stack[nodecnt++] = input[i];

        }

        for(register int i = 0; i < N; i++){
                cout << result[i] << ' ';
        }
        cout << '\n';

}
