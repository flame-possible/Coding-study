#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int input[101][3], N;
int L1[101] = {0,};
vector<pair<int, int>> v;
int a, b;

int main(){

	ios_base::sync_with_stdio(false);

	int len1 = 0;

	cin >> N;
	for(int i = 0; i<N; i++){
		cin >> a >> b;
		v.push_back(pair<int, int>(a,b));
	}

	sort(v.begin(), v.end());

	for(int i = 0; i<N; i++){

		auto pos = lower_bound(L1 + 1, L1 + len1 + 1, v[i].second);
        	*pos = v[i].second;
        	if(pos == L1 + len1 + 1){
        		len1++;
		}
	}
	cout << N - len1 << "\n";

	return 0;

}