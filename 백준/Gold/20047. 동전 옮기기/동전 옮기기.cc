#include <bits/stdc++.h>

using namespace std;

char finger[2];
string a, b;
string compare;
int N;


int find(int index, int fingercnt){

        if(index + fingercnt == N) return 1;

        if(compare[index] == b[index + fingercnt]){
                if(find(index + 1, fingercnt)) return 1;
        }

        if(fingercnt == 2) return 0;

        if(finger[fingercnt] == b[index + fingercnt]){
                if(find(index, fingercnt + 1)) return 1;
        }

        return 0;

}

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);


        cin >> N;


        cin >> a;
        cin >> b;

        int a1, a2;

        cin >> a1 >> a2;


        for(register int i = 0; i < a.length(); i++){
                if(i != a1 && i != a2){
                        compare += a[i];
                }
        }


        finger[0] = a[a1];
        finger[1] = a[a2];


        if(find(0, 0)){

                cout << "YES\n";

        }

        else{

                cout << "NO\n";

        }




        return 0;

}
