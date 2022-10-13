#include <iostream>
#include <algorithm>

using namespace std;

char input[27][27];

int check[27][27];

int group;
int group_num;

int group_list[700];

void DFS(int y, int x){

	if((check[y][x] & 1) || (input[y][x] != '1')){
		return;
	}

	check[y][x] = 1;
	group_num++;

	DFS(y+1, x);
	DFS(y-1, x);
	DFS(y, x+1);
	DFS(y, x-1);

	return;	

}

int main(){

	int N;

	cin >> N;

	for(register int i = 1; i <= N; i++){
		for(register int j = 1; j <= N; j++){
			cin >> input[i][j];
		}
	}

	for(register int i = 1; i <= N; i++){

		for(register int j = 1; j <= N; j++){
			if(!(check[i][j] & 1)){
				if(input[i][j] == '1'){
					group++;
					group_num = 0;
					DFS(i, j);
					group_list[group-1] = group_num;
				}
				else{
					check[i][j] = 1;
				}
			}
		}

	}

	cout << group << '\n';

	sort(group_list, group_list + group);

	for(register int i = 0; i < group; i++){
		cout << group_list[i] << '\n';
	}

	return 0;

}