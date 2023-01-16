#include <bits/stdc++.h>

using namespace std;

int group[1000001];

int is_group(int n){

        if(n == group[n]) return n;

        int result = is_group(group[n]);
        group[n] = result;
        return result;

}

int merge(int a, int b){

        a = is_group(a);
        b = is_group(b);

        if(a == b) return 1;

        group[a] = b;

        return 0;

}

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int n, m;

        cin >> n >> m;

        for(register int i = 0; i <= 1000001; i++){

                group[i] = i;

        }

        int pan, temp_1, temp_2;

        for(register int i = 0; i < m; i++){

                cin >> pan >> temp_1 >> temp_2;

                if(pan){

                        if(is_group(temp_1) == is_group(temp_2)){
                                cout << "YES\n";
                        }
                        else cout << "NO\n";

                }

                else{
                        merge(temp_1, temp_2);
                }

        }



        return 0;

}