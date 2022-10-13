#include <bits/stdc++.h>

#define MAX_TABLE 300001

using namespace std;

struct Node{
        string num;
        Node *next;
};

Node head[MAX_TABLE];
Node node[MAX_TABLE];
int node_cnt;

int hashing(string input){

        int div = 401;

        int i = 0;
        int len = input.length();

        while(i != len){
                div = ((div << 5) + (int)input[i]) % MAX_TABLE;
                i++;
        }

        return div % MAX_TABLE;

}

void insert_list(string input){

        int key = hashing(input);

        Node *temp = &head[key];

        Node *target = &node[node_cnt++];
        target->num = input;

        if(temp->next == 0){
                temp->next = target;
        }
        else{
                while(temp->next != 0){
                        temp = temp->next;
                }
                temp->next = target;
        }

        return;

}

int search_list(string input){

        int key = hashing(input);

        Node *temp = &head[key];

        while(temp->next != 0){

                if(temp->next->num == input){
                        return 2;
                }
                temp = temp->next;

        }

        return 0;

}


int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int N, M;

        cin >> N >> M;

        int result = N + M;

        string temp;

        for(register int i = 0; i < N; i++){
                cin >> temp;
                insert_list(temp);

        }

        for(register int i = 0; i < M; i++){
                cin >> temp;
                result -= search_list(temp);
        }

        cout << result << '\n';

        return 0;

}
