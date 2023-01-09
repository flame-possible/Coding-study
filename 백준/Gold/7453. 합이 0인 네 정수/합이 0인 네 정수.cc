#include <bits/stdc++.h>

using namespace std;

long long A[4001], B[4001], C[4001], D[4001];
long long temp_a[16000001], temp_b[16000001];

int main(){

        int n;

        cin >> n;

        for(register int i = 0; i < n; i++){
                cin >> A[i] >> B[i] >> C[i] >> D[i];
        }

        int cnt = 0;

        for(register int i = 0; i < n; i++){
                for(register int j = 0; j < n; j++){
                        temp_a[cnt] = A[i] + B[j];
                        temp_b[cnt++] = C[i] + D[j];
                }
        }

        sort(temp_a, temp_a + cnt);
        sort(temp_b, temp_b + cnt);

        int a_p = cnt-1;
        int b_p = 0;

        long long result = 0;

        while(1){

                if(a_p < 0 || b_p >= cnt) break;

                if(temp_a[a_p] + temp_b[b_p] < 0){
                        b_p++;
                }

                else if(temp_a[a_p] + temp_b[b_p] > 0){
                        a_p--;
                }

                else{

                        int temp = a_p;

                        long long a_result = 0;
                        long long b_result = 0;

                        while(temp_a[a_p] + temp_b[b_p] == 0){

                                if(a_p < 0) break;

                                a_result++;
                                a_p--;

                        }

                        while(temp_a[temp] + temp_b[b_p] == 0){

                                if(b_p >= cnt) break;

                                b_result++;
                                b_p++;
                        }

                        result += a_result * b_result;

                }

        }

        cout << result << '\n';



        return 0;

}
