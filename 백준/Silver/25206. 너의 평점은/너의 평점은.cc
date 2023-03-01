#include <bits/stdc++.h>

using namespace std;

int main(){

        //ios_base::sync_with_stdio(false);
        //cin.tie(0);

        string sub, score;
        double hak = 0, result = 0;

        int divide = 0;

        for(register int i = 0; i < 20; i++){

                cin >> sub >> hak >> score;

                if(score == "A+"){
                        result += 4.5 * hak;
                }
                else if(score == "A0"){
                        result += 4.0 * hak;
                }
                else if(score == "B+"){
                        result += 3.5 * hak;
                }
                else if(score == "B0"){
                        result += 3.0 * hak;
                }
                else if(score == "C+"){
                        result += 2.5 * hak;
                }
                else if(score == "C0"){
                        result += 2.0 * hak;
                }
                else if(score == "D+"){
                        result += 1.5 * hak;
                }
                else if(score == "D0"){
                        result += hak;
                }

                divide += hak;

                if(score == "P") divide -= hak;

        }

        printf("%.6lf\n", result / divide);

        //cout << result / divide << '\n';



        return 0;

}
