#include <iostream>

using namespace std;

int dis[100000] = {0,};
int city[100000] = {0,};

int main(){
ios_base::sync_with_stdio(false);
        cin.tie(0);
	int N;
	cin >> N;

	for(register int i = 0; i < N - 1; i++){
		cin >> dis[i];
	}

	for(register int i = 0; i < N; i++){
		cin >> city[i];
	}

	long long result = (long long)city[0] * (long long)dis[0];

	int price = city[0];
	int cur_dis = 0;

	for(register int i = 1; i < N - 1; i++){
		if(price > city[i]){
			result += (long long)price * (long long)cur_dis;
			cur_dis = 0;
			price = city[i];
		}
		cur_dis += dis[i];
	}
	if(cur_dis != 0){
		result += (long long)price * (long long)cur_dis;
	}

	cout << result << '\n';

	return 0;

}
