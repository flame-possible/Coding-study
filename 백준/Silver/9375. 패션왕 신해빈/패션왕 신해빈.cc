#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
ios_base::sync_with_stdio(false);
        cin.tie(0);
        int num;
        cin >> num;


        for(register int k = 0; k < num; k++){

                int n;

                cin >> n;

                string input1, input2;

                map<string, int> m;
                int ans = 1;

                for(register int i = 0; i < n; i++){

                        cin >> input1 >> input2;

                        if(m.find(input2) == m.end()){
                                m[input2] = 1;
                        }
                        else{
                                m[input2]++;
                        }

                }
                map<string, int>::iterator iter;
                for(iter = m.begin(); iter != m.end(); iter++){
                        ans *= iter->second + 1;
                }
                cout << ans - 1 << '\n';
        }

        return 0;

}
