#include <iostream>

using namespace std;

int main(){
ios_base::sync_with_stdio(false);
        cin.tie(0);
        int N;

        cin >> N;



        for(register int i = 0; i < N; i++){

                char input[51];
                cin >> input;

                register int j = 0;

                register int result = 0;

                while(input[j]){
                        if(input[j] == '('){
                                result++;
                        }
                        else{
                                result--;
                        }
                        if(result < 0){
                                break;
                        }
                        j++;

                }

                if(result == 0){
                        cout << "YES\n";
                }
                else{
                        cout << "NO\n";
                }

        }

        return 0;
}
