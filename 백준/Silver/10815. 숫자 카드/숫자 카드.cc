#include <iostream>

using namespace std;

int input[20000001];

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);


        int N;

        cin >> N;

        int temp;

        for(register int i = 0; i < N; i++){
                cin >> temp;

                input[temp+10000000] = 1;
        }

        int M;

        cin >> M;

        for(register int i = 0; i < M; i++){
                cin >> temp;

                if(input[temp+10000000] & 1){
                        cout << "1 ";
                }
                else{
                        cout << "0 ";
                }
        }
        cout << '\n';

        return 0;

}
