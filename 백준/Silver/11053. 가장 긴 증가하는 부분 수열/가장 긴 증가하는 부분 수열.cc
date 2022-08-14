#include <iostream>
#include <algorithm>

using namespace std;


int L[1001], len, N;
int main(){

	ios_base::sync_with_stdio(false);
	cin >> N;
    	for(int i = 1; i <= N; ++i) {
        	int here;
        	cin >> here;
        	auto pos = lower_bound(L + 1, L + len + 1, here);
        	*pos = here;
        	if(pos == L + len + 1)
        		len++;
    	}
    	cout << len;
    	return 0;

}
