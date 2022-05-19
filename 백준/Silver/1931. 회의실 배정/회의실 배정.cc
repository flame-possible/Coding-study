#include <iostream>
#include <algorithm>
using namespace std;

typedef struct st{
	unsigned int a;
	unsigned int b;
} info;
bool compare(info& a, info& b){
	if(a.b < b.b){
		return true;
	}else if(a.b == b.b){
		return (a.a < b.a);
	}else{
		return false;
	}
	
} 
int main() {
    ios_base::sync_with_stdio(false);
        cin.tie(0);
	int N;
	cin >> N;
	
	info array[100000];

	for(int i = 0; i < N; i++){
		cin >> array[i].a >> array[i].b;
	}
	sort(array, array+ N, compare);
	
	int count = 1;
	unsigned int temp = array[0].b;
	
	for(int i = 1; i < N; i++){
		
		if(array[i].a < temp){
			continue;
		}else{
			temp = array[i].b;
			count++;
		}
		
	}
	cout << count << endl;

	return 0;
}