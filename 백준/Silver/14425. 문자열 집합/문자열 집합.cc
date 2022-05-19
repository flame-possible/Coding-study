#include <iostream>
#include <bits/stdc++.h>

#define MAX_TABLE 1000001

using namespace std;

struct Node{

        string str;
        Node *next;
        Node *prev;

};

Node head[MAX_TABLE];

Node node[MAX_TABLE];
int node_cnt;

int hashing(string str){

        int hash = 401;
        int c;

        int i = 0;
        int len = str.length();

        while(i != len){
                hash = ((hash << 5) + (int)(str[i])) % MAX_TABLE;
                i++;
        }

        return hash % MAX_TABLE;

}

void insert_string(string input){

        int key = hashing(input);

        node[node_cnt++].str = input;

        Node *target = &node[node_cnt-1];

        Node *temp = &head[key];

        if(temp->next == 0){
                temp->next = target;
                return;
        }
        else{
                while(temp->next != 0){
                        temp = temp->next;
                }

                temp->next = target;
                return;

        }

        return;

}

int search_string(string input){

        int key = hashing(input);

        Node *temp = &head[key];

        while(temp->next != 0){
                if(temp->next->str == input){
                        return 1;
                }
                temp = temp->next;
        }

        return 0;

}

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    
        int N, M;

        cin >> N >> M;

        string temp;

        int result = 0;

        for(register int i = 0; i < N; i++){

                cin >> temp;

                insert_string(temp);

        }

        for(register int i = 0; i < M; i++){

                cin >> temp;

                result += search_string(temp);

        }

        cout << result << '\n';

        return 0;

}
