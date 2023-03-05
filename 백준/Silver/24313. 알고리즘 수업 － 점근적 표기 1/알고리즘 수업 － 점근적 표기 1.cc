#include <bits/stdc++.h>

using namespace std;

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int f1, f2, c, n;

        cin >> f1 >> f2;
        cin >> c;
        cin >> n;

        int temp1, temp2;

        temp1 = f1 * n;
        temp1 += f2;

        temp2 = c * n;

        if(f1 > c){
                cout << "0\n";
        }

        else if(f1 == c){
                if(temp1 > temp2){
                        cout << "0\n";
                }
                else{
                        cout << "1\n";
                }
        }

        else{
                if(temp1 > temp2){
                        cout << "0\n";
                }
                else{
                        cout << "1\n";
                }
        }

        return 0;

}
