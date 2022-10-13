#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define len 1000

using namespace std;

int table[len+2][len+2] = {0,};
int N;

int main(){
        ios_base::sync_with_stdio(false);

        string a, b;
        int max1 = 0;
        cin >> a >> b;

        int a_len = a.length();
        int b_len = b.length();

        for(int i = 1; i <= b_len; i++){
                for(int j = 1; j <= a_len; j++){
                        if(a[j-1] == b[i-1]){
                                table[i][j] = table[i-1][j-1] + 1;
                        }
                        else{
                                table[i][j] = max(table[i-1][j], table[i][j-1]);
                        }
                        if(table[i][j] > max1){
                                max1 = table[i][j];
                        }
                }
        }


        cout << max1 << "\n";

        return 0;
}
