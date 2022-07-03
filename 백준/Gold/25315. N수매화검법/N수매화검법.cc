#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

class begi {
    public:
        long long int x1, x2, y1, y2, w;
        begi(){
            this->x1 = 0;
            this->y1 = 0;
            this->x2 = 0;
            this->y2 = 0;
            this->w = 0;
        }

        bool operator <(begi &begi_1){
            return this->w < begi_1.w;
        }
};

bool compare(int a, int b){
    return a > b;
}

int ccw(long long int x1, long long int y1, long long int x2, long long int y2, long long int x3, long long int y3) {
    long long int temp = x1 * y2 + x2 * y3 + x3 * y1;
    temp -= y1 * x2 + y2 * x3 + y3 * x1;

    if (temp > 0)
        return 1;
    else if (!temp)
        return 0;
    else
        return -1;
}

int check_relate(begi begi_1, begi begi_2){

    int a = ccw(begi_1.x1, begi_1.y1, begi_1.x2, begi_1.y2, begi_2.x1, begi_2.y1) * 
            ccw(begi_1.x1, begi_1.y1, begi_1.x2, begi_1.y2, begi_2.x2, begi_2.y2);
    int b = ccw(begi_2.x1, begi_2.y1, begi_2.x2, begi_2.y2, begi_1.x1, begi_1.y1) * 
            ccw(begi_2.x1, begi_2.y1, begi_2.x2, begi_2.y2, begi_1.x2, begi_1.y2);
    
    if(a < 0 && b < 0) return 1;
    else return 0;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int input;

    cin >> input;

    long long int x1, x2, y1, y2, w;

    begi begi_1[2501];
    vector<int> checked;

    vector<int> relate[2501];

    long long int result = 0;

    for(register int i = 0; i < input; i++){
        cin >> x1 >> y1 >> x2 >> y2 >> w;
        if(x1 < x2){
            begi_1[i].x1 = x1;
            begi_1[i].y1 = y1;
            begi_1[i].x2 = x2;
            begi_1[i].y2 = y2;
            begi_1[i].w = w;
        }
        else{
            begi_1[i].x1 = x2;
            begi_1[i].y1 = y2;
            begi_1[i].x2 = x1;
            begi_1[i].y2 = y1;
            begi_1[i].w = w;
        }
        // cout << begi_1[i].x1 << ' ' << begi_1[i].y1 << ' ' << begi_1[i].x2 << ' ' << begi_1[i].y2 << ' ' << begi_1[i].w << '\n';
    }

    sort(begi_1, begi_1 + input);

    for(register int i = 0; i < input; i++){
        int sum = 0;
        for(register int j = i + 1; j < input; j++){
            sum += check_relate(begi_1[i], begi_1[j]);
        }
        result += (sum + 1) * begi_1[i].w;
    }

    cout << result << '\n';

    return 0;
}