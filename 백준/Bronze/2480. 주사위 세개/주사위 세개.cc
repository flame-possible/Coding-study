#include <iostream>

using namespace std;

int main(){

        int a, b, c;

        cin >> a >> b >> c;

        int result = 0;
        int max_in = 0;
        if(a > max_in){
                max_in = a;
        }
        if(b > max_in){
                max_in = b;
        }
        if(c > max_in){
                max_in = c;
        }

        if(a == b && b == c){
                result = 10000 + (a * 1000);
        }
        else if(a == b && b != c){
                result = 1000 + (a * 100);
        }
        else if(a == c && b != c){
                result = 1000 + (a * 100);
        }
        else if(b == c && a != c){
                result = 1000 + (b * 100);
        }
        else{
                result = (max_in * 100);
        }

        cout << result << '\n';

        return 0;

}
