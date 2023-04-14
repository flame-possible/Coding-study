#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = queue1.size() + queue2.size() * 2;
    
    long long int size_a = 0, size_b = 0;
    
    queue<int> input1, input2;
    
    for(int i = 0; i < queue1.size(); i++){
        
        size_a += queue1[i];
        input1.push(queue1[i]);
        
    }
    
    for(int i = 0; i < queue2.size(); i++){
        
        size_b += queue2[i];
        input2.push(queue2[i]);
        
    }
    
    int result = 0;
    
    while(size_a != size_b){
        
        if(result > answer){
            answer = -1;
            break;
        }
        
        result++;
            
        if(size_a > size_b){
            size_a -= input1.front();
            size_b += input1.front();
            input2.push(input1.front());
            input1.pop();
            
        }
        else{
            size_b -= input2.front();
            size_a += input2.front();
            input1.push(input2.front());
            input2.pop();
            
        }
    }
    
    if(answer != -1){
        answer = result;
    }
    
    
    return answer;
}