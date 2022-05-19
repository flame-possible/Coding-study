#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define MAX_TABLE 500001

using namespace std;

vector <string> output;

struct Node{

        string key;
        int count;
        Node* next_node;

};

Node hash_table[500001];

Node hash_node[500001];

int out_cnt = 0;

bool compare(string s1, string s2){
    return s1 < s2;
}

int hash_1(string str){

        int hash = 401;



        int c;
        int i = 0;
        while(str[i] != 0){
                hash = ((hash << 4) + int(str[i])) % MAX_TABLE;
                i++;
        }
        return hash % MAX_TABLE;

}

void insert_hash(string str, int input_num){

        int hash_num = hash_1(str);


        hash_node[input_num].key = str;


        if(hash_table[hash_num].count == 0){
                hash_table[hash_num].next_node = &hash_node[input_num];
                hash_table[hash_num].count++;
                return;
        }
        else{
                Node* temp = hash_table[hash_num].next_node;
                for(register int i = 0; i < hash_table[hash_num].count; i++){
                        /*if(!(strcmp(str, hash_table[hash_num].key))){
                                strcpy(hash_table[hash_num].key, output[out_cnt++]);
                                return;
                        }*/
                        if(i < hash_table[hash_num].count - 1){
                                temp = temp->next_node;
                        }
                }
                temp->next_node = &hash_node[input_num];
                hash_table[hash_num].count++;

        }

}

void check_table(string str){

        int hash_num = hash_1(str);


        if(hash_table[hash_num].count == 0){
                return;
        }
        else{

                Node* temp = hash_table[hash_num].next_node;
                for(register int i = 0; i < hash_table[hash_num].count; i++){
                        if(str == temp->key){
                                output.push_back(temp->key);
                                return;
                        }
                        if(i < hash_table[hash_num].count - 1){
                                temp = temp->next_node;
                        }
                }


        }


}


int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);

        int N, M;

        cin >> N >> M;

        string temp;

        for(register int i = 0; i < N; i++){
                cin >> temp;
                insert_hash(temp, i);

        }

        for(register int i = 0; i < M; i++){
                cin >> temp;
                check_table(temp);

        }

        sort(output.begin(), output.end(), compare);

        cout << output.size() << '\n';

        for(register int i = 0; i < output.size(); i++){
                cout << output[i] << '\n';
        }


        return 0;

}
