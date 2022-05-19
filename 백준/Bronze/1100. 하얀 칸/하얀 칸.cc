#include <iostream>

using namespace std;

int main(){

        char input = 0;

        int count = 0;

        for(register int i = 1; i < 9; i++){

                for(register int j = 1; j < 9; j++){
                        cin >> input;
                        if(i & 1){
                                if(j & 1 && input == 'F'){
                                        count++;
                                }
                        }
                        else{
                                if(!(j & 1) && input == 'F'){
                                        count++;
                                }
                        }
                }

        }

        cout << count << '\n';

        return 0;

}
