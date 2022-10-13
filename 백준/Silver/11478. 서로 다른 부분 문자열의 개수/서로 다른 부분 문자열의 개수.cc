#include <bits/stdc++.h>

#define MAX_TABLE 1000001

using namespace std;

struct Node{

        string str;
        Node *next;

};

Node head[MAX_TABLE];
Node node[MAX_TABLE];
int node_cnt;
int result;

int hashing(string input){

        unsigned long div = 5381;

        int i = 0;
        int len = input.length();

        while(i !=  len/4){
                div = ((div << 4) + (int)input[i]) % MAX_TABLE;
                i++;
        }

        return div % MAX_TABLE;

}

void insert_list(string input){

        int key = hashing(input);

        Node *temp = &head[key];
        Node *target = &node[node_cnt++];

        target->str = input;

        if(temp->next == 0){
                temp->next = target;
                result++;
                return;
        }
        else{
                while(temp->next != 0){
                        if(temp->next->str == input){
                                return;
                        }
                        temp = temp->next;
                }
                temp->next = target;
                result++;
        }

        return;

}

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        string input;

        cin >> input;

        string temp;

        temp.clear();

        for(register int i = 0; i < input.length(); i++){
                for(register int j = i; j < input.length(); j++){
                        temp += input[j];
                        insert_list(temp);
                }
                temp.clear();
        }

        cout << result << '\n';

        return 0;

}
