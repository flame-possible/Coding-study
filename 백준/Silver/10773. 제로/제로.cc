#include <iostream>

using namespace std;

int stack[100001];
int nodecnt = 0;

int main(){
ios_base::sync_with_stdio(false);
        cin.tie(0);
        int N;

        cin >> N;

        for(register int i = 0; i < N; i++){

                int temp;
                cin >> temp;

                if(temp == 0){
                        nodecnt--;
                        continue;
                }
                else{
                        stack[nodecnt++] = temp;
                }

        }

        int result = 0;

        for(register int i = 0; i < nodecnt; i++){
                result += stack[i];
        }

        cout << result << '\n';

        return 0;
}
