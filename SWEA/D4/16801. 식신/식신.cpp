/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(register int t = 1; t <= T; t++){

                int N;
                long long int K;

                cin >> N >> K;

                vector<int> player;
                vector<int> food;

                for(register int i = 0; i < N; i++){
                        int temp;

                        cin >> temp;

                        player.push_back(temp);
                }
                for(register int i = 0; i < N; i++){
                        int temp;

                        cin >> temp;

                        food.push_back(temp);
                }
                sort(player.begin(), player.end(), less<int>());
                sort(food.begin(), food.end(), greater<int>());

                vector<long long int> score;

                for(register int i = 0; i < N; i++){
                        score.push_back((long long int)player[i] * (long long int)food[i]);
                }

                long long int low = 0, high = 1000000000000000001;

                while(low < high){

                        long long int cnt = 0, mid = (low + high) / 2;

                        for(register int i = 0; i < N; i++){
                                if(mid < score[i]){ // mid가 score보다 크면 어차피 의미가 없다.
                                        if(cnt > K) break;

                                        cnt += player[i] - (mid / food[i]);
                                        // mid < food * player == mid / food < player
                                        // 여기서 player는 항상 mid / food보다 크기 때문에 -가 cnt에 더해질 일은 없다.
                                }
                        }

                        if(cnt > K){
                                low = mid + 1;
                        }

                        else{
                                high = mid;
                        }

                }

                cout << "#" << t << ' ' << low << '\n';


        }

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}