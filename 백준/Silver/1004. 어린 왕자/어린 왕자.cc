#include <bits/stdc++.h>

using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	
	cin >> T;

	for(register int test = 0; test < T; test++){

		int x1, y1;
		int x2, y2;

		cin >> x1 >> y1 >> x2 >> y2;

		int n;

		cin >> n;

		int result = 0;

		for(register int i = 0; i < n; i++){

			int start_pass = 0;
			int end_pass = 0;
			int cx, cy, r;

			cin >> cx >> cy >> r;


/*
			if((temp_x_min <= x1 && temp_x_max >= x1) && (temp_y_min <= y1 && temp_y_max >= y1)){
				temp_x_min--;
				for(register int j = 0; j < (r * 2) + 1; j++){
					temp_x_min++;
					if(j <= r){
						y_plus++;
						y_minus--;
					}
					else{
						y_plus--;
						y_minus++;
					}
					if(temp_x_min == x1){
						//cout << "x1 " << y_minus << ' ' << y_plus << '\n';
						if(y_plus >= y1 && y_minus <= y1){
							
							start_pass++;
							break;
						}
						break;
					}
				}
			}

			temp_x_min = cx - r;
			y_plus = cy - 1;
			y_minus = cy + 1;

			if((temp_x_min <= x2 && temp_x_max >= x2) && (temp_y_min <= y2 && temp_y_max >= y2)){
                                temp_x_min--;
                                for(register int j = 0; j < (r * 2) + 1; j++){
                                        temp_x_min++;
                                        if(j <= r){
                                                y_plus++;
                                                y_minus--;
                                        }
                                        else{
                                                y_plus--;
                                                y_minus++;
                                        }
                                        if(temp_x_min == x2){
                                                if(y_plus >= y2 && y_minus <= y2){
                                                        end_pass++;
                                                        break;
                                                }
						break;
                                        }
                                }
                        }

//			cout << start_pass << ' ' << end_pass << '\n';
*/

			if((x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy) < r * r) start_pass++;
			if((x2 - cx) * (x2 - cx) + (y2 - cy) * (y2 - cy) < r * r) end_pass++;
			

			if((start_pass & 1) && (end_pass & 1)){
				continue;
			}
			result += start_pass + end_pass;

		}

		cout << result << '\n';

	}

}