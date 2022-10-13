#include <iostream>

using namespace std;

int input[1001][1001] = {0,};
int check1[1001] = {0,};
int check2[1001] = {0,};

int output1[1001] = {0,};
int output2[1001] = {0,};
int output_cnt_1 = 0;
int output_cnt_2 = 0;

int bfs_list[1001] = {0,};
int bfs_cnt = 0;

int N, M, V;

void DFS(int n){

	if(check1[n] & 1){
		return;
	}
	check1[n] = 1;
	output1[output_cnt_1++] = n;

	for(register int i = 1; i <= N; i++){
		if(input[n][i] & 1){
			DFS(i);
		}
	}
	return;
}

void BFS(int n){

	for(register int i = 1; i <= N; i++){
		if(input[n][i] & 1){
			if(!check2[i]){
				bfs_list[bfs_cnt++] = i;
				output2[output_cnt_2++] = i;
				check2[i] = 1;
			}
		}
	}


}

int main(){

	ios_base::sync_with_stdio(false); 
	cin.tie(0);


	cin >> N >> M >> V;

	for(register int i = 0; i < M; i++){
		int temp_a, temp_b;

		cin >> temp_a >> temp_b;

		input[temp_a][temp_b] = 1;
		input[temp_b][temp_a] = 1;
	}

	DFS(V);

	for(register int i = 0; i < output_cnt_1; i++){
		cout << output1[i] << ' ';
	}
	cout << '\n';

	check2[V] = 1;
	output2[output_cnt_2++] = V;

	bfs_list[bfs_cnt++] = V;

	for(register int i = 0; i < bfs_cnt; i++){
		BFS(bfs_list[i]);
	}

	for(register int i = 0; i < output_cnt_2; i++){
                cout << output2[i] << ' ';
        }
        cout << '\n';

	return 0;

}
