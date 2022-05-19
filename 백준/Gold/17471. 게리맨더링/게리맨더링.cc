#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

#define len 100000

using namespace std;

struct Node{

        int key;
        int child_num;
        int index;
        Node *child[11];

};

int N, M, K;
int input[51][51] = {0,};
int input_temp[51][51] = {0,};
int counting = 6000;
int result = 6000;
bool visited[11];
vector <int> group_a;
vector <int> group_b;

int main(void)
{
        cin.tie(NULL);
        ios::sync_with_stdio(false);

        int set1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        cin >> N;
        Node node[11];
        for(int i = 1; i <= N; i++){
                cin >> node[i].key;
                node[i].index = i;
        }
        for(int i = 1; i <= N; i++){
                cin >> M;
                node[i].child_num = M;
                for(int j = 1; j <= M; j++){
                        cin >> K;
                        node[i].child[j] = &node[K];
                }
        }

        for(int i = 1; i < (1 << N) - 1; i++){
                for(int j = 0; j < N; j++){
                        visited[j] = false;
                }
                for(int j = 0; j < N; j++){
                        if(i & (1 << j)){
                                group_a.push_back(set1[j]);
                                visited[set1[j]] = true;
                        }
                }
                for(int j = 0; j < N; j++){
                        if(!visited[set1[j]]){
                                group_b.push_back(set1[j]);
                        }
                }
                int temp1 = 0;
                int temp2 = 0;

                for(int j = 0; j < group_a.size(); j++){
                        temp1 += node[group_a[j]].key;
                }
                for(int j = 0; j < group_b.size(); j++){
                        temp2 += node[group_b[j]].key;
                }
                int temp_result = temp1 - temp2;

                if(temp_result < 0){
                        temp_result *= -1;
                }
                if(result > temp_result){
                //if(temp_result == 2){
                        queue<int> q;
                        q.push(group_a.front());
                        int visit[11] = {0,};
                /*      for(int j = 0; j < group_a.size(); j++){
                                cout << group_a[j] << ' ';
                        }
                        cout << '\n';

                        for(int j = 0; j < group_b.size(); j++){
                                cout << group_b[j] << ' ';
                        }
                        cout << '\n';

                        cout << result << '\n';
*/
                        while(!q.empty()){
                                int x = q.front();
//                              cout << "x_1 "  << x << ' ';
                                q.pop();
                                visit[x] = 1;
                                for(int j = 1; j <= node[x].child_num; j++){
                                        int y = x;
                                        for(int o = 1; o <= N; o++){
                                                if(node[x].child[j] == &node[o]){
                                                        y = o;
                                                        int suc = 0;
                                                        for(int p = 0; p < group_a.size(); p++){
                                                                if(group_a[p] == o){
                                                                        suc = 1;
                                                                }
                                                        }
                                                        if(visit[y] == 0 && suc == 1){
                                                                q.push(y);
                                                                visit[y] = 1;
                                                        }

                                                }
                                        }
                                }
                        }
//                      cout << '\n';
                        int suc_a = 0;
                        for(int j = 0; j < group_a.size(); j++){
                                if(visit[group_a[j]] == 0){
                                        suc_a = 1;
                                }
                        }
                        if(suc_a == 1){
                                group_a.clear();
                                group_b.clear();
                                continue;
                        }
                        for(int j = 0; j < 11; j++){
                                visit[j] = 0;
                        }
                        q.push(group_b.front());
                        while(!q.empty()){
                                int x = q.front();
//                              cout << "x_2 " << x << ' ';
                                q.pop();
                                visit[x] = 1;
                                for(int j = 1; j <= node[x].child_num; j++){
                                        int y = x;
                                        for(int o = 1; o <= N; o++){
                                                if(node[x].child[j] == &node[o]){
                                                        y = o;
                                                        int suc = 0;
                                                        for(int p = 0; p < group_b.size(); p++){
                                                                if(group_b[p] == o){
                                                                        suc = 1;
                                                                }
                                                        }
                                                        if(visit[y] == 0 && suc == 1){
                                                                q.push(y);
                                                                visit[y] = 1;
                                                        }
                                                }
                                        }
                                }
                        }
//                      cout << '\n';
                        for(int j = 0; j < group_b.size(); j++){
                                if(visit[group_b[j]] == 0){
                                        suc_a = 1;
                                }
                        }
                        if(suc_a == 1){
                                group_a.clear();
                                group_b.clear();
                                continue;
                        }


                        result = temp_result;
/*                      for(int j = 0; j < group_a.size(); j++){
                                cout << group_a[j] << ' ';
                        }
                        cout << '\n';

                        for(int j = 0; j < group_b.size(); j++){
                                cout << group_b[j] << ' ';
                        }
                        cout << '\n';

                        cout << result << '\n';
*/              }

                group_a.clear();
                group_b.clear();
        }

        if(result == 6000){
                cout << "-1" << '\n';
        }
        else{
                cout << result << '\n';
        }
        return 0;
}
