#include <iostream>
#include <algorithm>

using namespace std;


int input[1002], L1[1002], L2[1002], len1, len2, N;
int main(){
	int long1[1002] = {0,};
	int long2[1002] = {0,};
	int ans1, ans2;
	int max = 0;
	ios_base::sync_with_stdio(false);
	cin >> N;
    	for(int i = 1; i <= N; ++i) {
        	
        	cin >> input[i];
        	auto pos = lower_bound(L1 + 1, L1 + len1 + 1, input[i]);
        	*pos = input[i];
        	if(pos == L1 + len1 + 1){
        		len1++;
		}
		long1[i] = len1;
    	}
	for(int i = N; i > 0; i--){
		auto pos = lower_bound(L2 + 1, L2 + len2 + 1, input[i]);
		*pos = input[i];
		if(pos == L2 + len2 + 1){
			len2++;
		}
		long2[i] = len2;
	}
    	
	for(int i = 1; i <= N; i++){
		if(max < long1[i] + long2[i] - 1){
			max = long1[i] + long2[i] - 1;
		}
	}
	cout << max << "\n";

	return 0;

}