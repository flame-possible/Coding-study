#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define len 100000

using namespace std;

int N;
int input[51][20] = {0,};
int counting = 0;
int result = 0;
int m;
vector<int> order;
vector<int> temp;
bool visit[10];

void dfs(){
	if(temp.size() == m){
		temp.insert(temp.begin()+3, 1, 1);
/*		
		for(int i = 0; i < m; i++){
			cout << temp[i] << ' ';
		}
		cout << '\n';
*/		int out_count = 0;
		int taja = 0;
        	for(int i = 1; i <= N; i++){
			int juja[3] = {0,};
			out_count = 0;
                	while(out_count < 3){
				if(input[i][temp[taja]] == 0){
					out_count++;
				}
				else if(input[i][temp[taja]] == 1){
					if(juja[2] == 1){
						counting += 1;
						juja[2] = 0;
					}
					if(juja[1] == 1){
						juja[2] += 1;
						juja[1] = 0;
					}
					if(juja[0] == 1){
						juja[1] += 1;
						juja[0] = 0;
					}
					
					juja[0] += 1;
					
				}
                                else if(input[i][temp[taja]] == 2){
                                	if(juja[2] == 1){
                                                counting += 1;
                                                juja[2] = 0;
                                        }
                                        if(juja[1] == 1){
						counting += 1;
                                                juja[1] = 0;
                                        }
                                        if(juja[0] == 1){
                                                juja[2] += 1;
						juja[0] = 0;
                                        }
                                        
                                        juja[1] += 1;
                                        
                                }
                                else if(input[i][temp[taja]] == 3){
                                	if(juja[2] == 1){
                                                counting += 1;
                                                juja[2] = 0;
                                        }
                                        if(juja[1] == 1){
                                                counting += 1;
                                                juja[1] = 0;
                                        }
                                        if(juja[0] == 1){
						counting += 1;
                                                juja[0] = 0;
                                        }
                                        
                                        juja[2] += 1;
                                        
                                }
				else{
					counting += juja[0] + juja[1] + juja[2] + 1;
					for(int k = 0; k <3; k++){
						juja[k] = 0;
					}
				}

				if(taja == 8){
					taja = 0;
				}
				else{
					taja += 1;
				}
//				cout << juja[0] << ' ' << juja[1] << ' ' << juja[2] << "counting " << counting << '\n';
                	}
        	}
//		cout << "counting " << counting << " result " << result << '\n';
		if(counting > result){
			result = counting;
		}
		counting = 0;
			
                temp.erase(temp.begin()+3, temp.begin()+4);
		return;		
	}

	for(int i = 0; i < order.size(); i++){
		if(!visit[i]){
			visit[i] = true;
			temp.push_back(order[i]);
			dfs();
			temp.pop_back();
			visit[i] = false;
		}
	}
	

}

int main(void)
{
        cin.tie(NULL);
        ios::sync_with_stdio(false);
	
	cin >> N;

        for(int i = 1; i <= N; i++){
                for(int j = 1; j <= 9; j++){
                        cin >> input[i][j];
                }
        }

	m = 8;

	for(int i = 2; i <= 9; i++){
		order.push_back(i);
	}

	dfs();

        cout << result << '\n';
        
	return 0;
}
