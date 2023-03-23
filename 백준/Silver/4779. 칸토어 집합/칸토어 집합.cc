#include <bits/stdc++.h>

using namespace std;

char input[600000];

void cantoer(int start, int end){

        if(start >= end || end < 3 || end - start <= 1) return;

        int cut_1 = (end - start + 1)/3;
        int cut_2 = cut_1 * 2;

        for(register int i = cut_1 + start; i < start + cut_2; i++){
                input[i] = ' ';
        }

        cantoer(start, start + cut_1);
        cantoer(start + cut_2, end);

        return;

}

int main(){

//      ios_base::sync_with_stdio(false);
//      cin.tie(0);

        int N;

        while(1){

                cin >> N;

                if(cin.eof() == 1) break;

                input[0] = ' ';

                for(register int i = 1; i <= pow(3, N); i++){
                        input[i] = '-';
                }

                cantoer(1, pow(3, N));

                for(register int i = 1; i <= pow(3, N); i++){
                        cout << input[i];
                }

                cout << '\n';

        }

        return 0;

}
