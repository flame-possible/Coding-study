#include <bits/stdc++.h>

#define MAX_TABLE 100001

using namespace std;

struct Node{

        string str;
        int num;
        Node *next;

};

Node node_head[MAX_TABLE];
Node node[MAX_TABLE];
int node_cnt;

string num_list[MAX_TABLE];

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

void insert_str(string input, int num){

        int key = hashing(input);

        Node *temp = &node_head[key];
        Node *target = &node[node_cnt++];

        target->str = input;
        target->num = num;

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

int search_str(string input){

        int key = hashing(input);

        Node *temp = &node_head[key];

        while(temp->next != 0){
                if(temp->next->str == input){
                        break;
                }
                temp = temp->next;
        }

        return temp->next->num;

}

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int N, M;

        cin >> N >> M;

        string temp;

        for(register int i = 1; i <= N; i++){
                cin >> temp;
                num_list[i] = temp;
                insert_str(temp, i);
        }

        for(register int i = 0; i < M; i++){
                cin >> temp;
                if(temp[0] >= '1' && temp[0] <= '9'){
                        register int num_temp = 0;
                        for(register int j = 0; j < temp.length(); j++){
                                num_temp += temp[j] - '0';
                                if(j != temp.length() - 1){
                                        num_temp *= 10;
                                }
                        }
                        cout << num_list[num_temp] << '\n';
                }
                else{
                        cout << search_str(temp) << '\n';
                }
        }

        return 0;

}
