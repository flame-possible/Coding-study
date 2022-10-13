#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define len 100000

using namespace std;

int X, Y, D;
int input[20][20] = {0,};
int counting = 0;
int result = 0;

void start(int a, int b, int c){
	int input1[20][20] = {0,};

	for(int i = 1; i <= Y; i++){
		for(int j = 1; j <= X; j++){
			input1[i][j] = input[i][j];
		}
	}

	for(int i = Y + 1; i > 1; i--){
		int temp1[2] = {0,};
		int temp2[2] = {0,};
		int temp3[2] = {0,};

		int temp1_1 = 0;
		int temp2_1 = 0;
		int temp3_1 = 0;

//		cout << i << ".\n"; 

		int small_1 = 20;
		int small_2 = 20;


		for(int j = 1; j <= D; j++){
			for(int k = -(D - j); k <= D - j; k++){
				int temp_temp = k;
				if(k < 0){
					temp_temp = k * -1;
				}
				if(i-j < 1 || a+k < 1 || a+k > X){
                                        continue;
                                }
				if(input1[i-j][a+k] == 1 && (j + temp_temp) <= small_1){
					if(small_1 == j + temp_temp){
						if(small_2 > k){
                                                	temp1[0] = i-j;
                                                	temp1[1] = a+k;
                                                	temp1_1 = 1;
                                                	small_1 = j + temp_temp;
                                                	small_2 = k;
                                        	}
					}
					else{	
						temp1[0] = i-j;
						temp1[1] = a+k;
						temp1_1 = 1;
						small_1 = j + temp_temp;
						small_2 = k;
					}
				}
			}
		}

		small_1 = 20;
		small_2 = 20;

		for(int j = 1; j <= D; j++){
                        for(int k = -(D - j); k <= D - j; k++){
                                int temp_temp = k;
				if(k < 0){
                                        temp_temp = k * -1;
                                }
                                if(i-j < 1 || b+k < 1 || b+k > X){
                                        continue;
                                }
				if(input1[i-j][b+k] == 1 && (j + temp_temp) <= small_1){
					if(small_1 == j + temp_temp){
						if(small_2 > k){
                                                	temp2[0] = i-j;
                                                	temp2[1] = b+k;
                                                	temp2_1 = 1;
                                                	small_1 = j + temp_temp;
                                                	small_2 = k;
                                        	}
					}
					else{
                                        	temp2[0] = i-j;
                                        	temp2[1] = b+k;
						temp2_1 = 1;
                                        	small_1 = j + temp_temp;
                                        	small_2 = k;
					}
                                }
                        }
                }

		small_1 = 20;
		small_2 = 20;

		for(int j = 1; j <= D; j++){
                        for(int k = -(D - j); k <= D - j; k++){
                                int temp_temp = k;
                                if(k < 0){
                                        temp_temp = k * -1;
                                }
                                if(i-j < 1 || c+k < 1 || c+k > X){
                                        continue;
                                }
				if(input1[i-j][c+k] == 1 && (j + temp_temp) <= small_1){
					if(small_1 == j + temp_temp){
						if(small_2 > k){
                                                	temp3[0] = i-j;
                                                	temp3[1] = c+k;
                                                	temp3_1 = 1;
                                                	small_1 = j + temp_temp;
                                                	small_2 = k;
                                        	}
					}
					else{
                                        	temp3[0] = i-j;
                                        	temp3[1] = c+k;
						temp3_1 = 1;
                                        	small_1 = j + temp_temp;
                                        	small_2 = k;
					}
                                }
                        }
                }
		if(temp1_1 == 1 || temp2_1 == 1 || temp3_1 == 1){
			
			if(temp1_1 == 1 && temp2_1 == 0 && temp3_1 == 0){
				input1[temp1[0]][temp1[1]] = 0;
				counting++;
			}
			else if(temp1_1 == 0 && temp2_1 == 1 && temp3_1 == 0){
                                input1[temp2[0]][temp2[1]] = 0;
				counting++;
			}
                        else if(temp1_1 == 0 && temp2_1 == 0 && temp3_1 == 1){
                                input1[temp3[0]][temp3[1]] = 0;
                                counting++;
                        }
			else if(temp1_1 == 1 && temp2_1 == 1 && temp3_1 == 0){
				if(temp1[0] == temp2[0] && temp1[1] == temp2[1]){
                                	input1[temp1[0]][temp1[1]] = 0;
                        		counting++;
				}
				else{
	                                input1[temp1[0]][temp1[1]] = 0;
	                                input1[temp2[0]][temp2[1]] = 0;

					counting += 2;
				}
			}
                        else if(temp1_1 == 1 && temp2_1 == 0 && temp3_1 == 1){
                                if(temp1[0] == temp3[0] && temp1[1] == temp3[1]){
                                        input1[temp1[0]][temp1[1]] = 0;
                                        counting++;
                                }
                                else{
                                        input1[temp1[0]][temp1[1]] = 0;
                                        input1[temp3[0]][temp3[1]] = 0;
                                        counting += 2;
                                }
                        }
                        else if(temp1_1 == 0 && temp2_1 == 1 && temp3_1 == 1){
                                if(temp2[0] == temp3[0] && temp2[1] == temp3[1]){
                                        input1[temp2[0]][temp2[1]] = 0;
                                        counting++;
                                }
                                else{
                                        input1[temp3[0]][temp3[1]] = 0;
                                        input1[temp2[0]][temp2[1]] = 0;
                                        counting += 2;
                                }
                        }
                        else if(temp1_1 == 1 && temp2_1 == 1 && temp3_1 == 1){
				if(temp1[0] == temp2[0] && temp1[1] == temp2[1]){
                                        input1[temp1[0]][temp1[1]] = 0;
               			        counting++;
                		        if(temp2[0] == temp3[0] && temp2[1] == temp3[1]){
                		                continue;
                		        }
                		        else{
                                        	input1[temp3[0]][temp3[1]] = 0;
                		                counting++;
                		        }
        		        }
				else if(temp2[0] == temp3[0] && temp2[1] == temp3[1]){
					input1[temp1[0]][temp1[1]] = 0;
                                        input1[temp2[0]][temp2[1]] = 0;
					counting += 2;
					
				}
        		        else{
                                        input1[temp1[0]][temp1[1]] = 0;
                                        input1[temp2[0]][temp2[1]] = 0;
                                        input1[temp3[0]][temp3[1]] = 0;
        		                counting += 3;
		                }

                        }
			

		}
//		cout << "temp1 " << temp1_1 <<	" temp2 " << temp2_1 << " temp3 " << temp3_1 << '\n';
/*		cout << counting << ' ' << i << '\n';
		for(int p = 1; p <= Y; p++){
                        for(int o = 1; o <= X; o++){
                                cout << input1[p][o] << ' ';
                        }
                        cout << '\n';
                }		
*/
	}
}

int main(void)
{
        cin.tie(NULL);
        ios::sync_with_stdio(false);

        cin >> Y >> X >> D;
        for(int i = 1; i <= Y; i++){
                for(int j = 1; j <= X; j++){
                        cin >> input[i][j];
                }
        }

	for(int i = 1; i <= X - 2; i++){
		for(int j = i + 1; j <= X - 1; j++){
			for(int k = j + 1; k <= X; k++){
				start(i, j, k);
//				cout << "start counting" << counting << "ijk"  << i << j << k << '\n';
				if(counting > result){
					result = counting;
				}
				counting = 0;
			}
		}
	}

        cout << result << '\n';

        return 0;
}