#include <bits/stdc++.h>

using namespace std;

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        long long X, Y;
        int Z;

        cin >> X >> Y;

        Z = (Y * 100) / X;

        if(Z >= 99){
                cout << "-1\n";
                return 0;
        }


        int l = 1;
        int r = 1000000000;

        int mid = (l + r) / 2;
        int result = 0;

        while(l <= r){

                mid = (l + r) / 2;

                int temp = ((Y + mid) * 100) / (X + mid);

                if(temp > Z){

                        r = mid - 1;
                        result = mid;
                }

                else{
                        l = mid + 1;
                }


        }

        cout << result << '\n';

        return 0;

}
