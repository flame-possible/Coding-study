#include <iostream>

using namespace std;

char input[200001] = {0,};
int result[26][200003] = {0,};


int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        cin >> input;

        register int i = 0;

        while(input[i] != 0){


                for(register int j = 0; j < 26; j++){
                        result[j][i+1] += result[j][i];
                }

                result[input[i] - 'a'][i+1]++;


                i++;

        }

        int n;

        cin >> n;

        char a;

        int l, r;

        for(i = 0; i < n; i++){
                cin >> a >> l >> r;

                cout << result[a - 'a'][r + 1] - result[a - 'a'][l] << '\n';
        }


        return 0;

}
