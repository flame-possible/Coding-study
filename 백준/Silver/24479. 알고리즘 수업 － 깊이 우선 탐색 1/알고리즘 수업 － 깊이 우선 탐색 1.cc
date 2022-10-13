#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int check[100001];

int output[100001];
int output_cnt;

int N, M, R;


/*
struct Node{

        int cnt;
        Node *next;
        Node *prev;

};

Node node[400002];
int nodecnt;
Node head[100001];

int check[100001];

int output[100001];
int output_cnt;

int N, M, R;

void insert_node(int top, int n){


        node[nodecnt++].cnt = n;

        Node *temp = &head[top];

        Node *temp1 = &node[nodecnt-1];

        while(temp->next != 0){
                if(temp->next->cnt > n) break;
                temp = temp->next;
        }

        if(temp->next == 0){
                temp->next = temp1;
                temp1->prev = temp;
        }
        else{
                temp1->next = temp->next;
                temp->next->prev = temp1;
                temp1->prev = temp;
                temp->next = temp1;
        }

        return;
}
*/

vector<int> v[100001];

void DFS(int n){


        if(check[n] & 1){
                return;
        }

        check[n] = 1;
        output[n] = ++output_cnt;

        for(register int i = 0; i < v[n].size(); i++){
                DFS(v[n][i]);
        }

//      Node *temp = &head[n];
/*
        while(temp->next != 0){
                if(!(check[temp->next->cnt])){
                        DFS(temp->next->cnt);
                }
                temp = temp->next;

        }
*/
        return;


}

int main(){


        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        cin >> N >> M >> R;

        int temp_1, temp_2;

        for(register int i = 0; i < M; i++){
                cin >> temp_1 >> temp_2;
                //insert_node(temp_1, temp_2);
                //insert_node(temp_2, temp_1);
                v[temp_1].push_back(temp_2);
                v[temp_2].push_back(temp_1);
        }

        for(register int i = 1; i <= N; i++){
                sort(v[i].begin(), v[i].end());
        }

        DFS(R);

        for(register int i = 1; i <= N; i++){
                cout << output[i] << '\n';
        }

        return 0;

}
