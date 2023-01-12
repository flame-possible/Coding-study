#include <bits/stdc++.h>

using namespace std;

int jong[500001], suk[500001];
int result[500001];

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int N, H;

        cin >> N >> H;

        int temp;

        for(register int i = 1; i <= N; i++){

                cin >> temp;

                if(i & 1) suk[temp]++;
                else jong[H - temp + 1]++;

        }

        for(register int i = 1; i <= H; i++){

                jong[i] += jong[i-1];
                suk[H - i] += suk[H - i + 1];

        }

        int result = 2e9;
        int cnt = 0;

        for(register int i = 1; i <= H; i++){
                if(jong[i] + suk[i] < result){
                        cnt = 1;
                        result = jong[i] + suk[i];
                }
                else if(jong[i] + suk[i] == result) cnt++;
        }

        cout << result << ' ' << cnt << '\n';

        return 0;

}
