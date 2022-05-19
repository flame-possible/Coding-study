#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int input[100001] = {0,};
int N;
/*
void quicksort(int start, int end){

        if(start >= end) return;

        int pivot = input[(start+end)/2];

        int left = start;
        int right = end;


        while(left <= right){

                while(input[left] < pivot) left++;
                while(input[right] > pivot) right--;

                if(left <= right){
                        int temp = input[left];
                        input[left] = input[right];
                        input[right] = temp;
                        left++;
                        right--;
                }

        }

        quicksort(start, right);
        quicksort(left, end);

}
*/
bool compare(int a, int b){
        return a < b;
}
int search_1(int n){

        int left = 0;
        int right = N - 1;

        int mid = (left + right) / 2;
        while(left <= right){
                mid = (left + right) / 2;
                if(input[mid] > n){
                        right = mid - 1;
                }
                else if(input[mid] < n){
                        left = mid + 1;
                }
                else{
                        return 1;
                }
        }

        return 0;

}

int main(){
        cin.tie(NULL);
        ios_base::sync_with_stdio(false);

        cin >> N;

        for(register int i = 0; i < N; i++){

                cin >> input[i];
        }

        sort(input, input + N, compare);

        int M;
        cin >> M;

        for(register int i = 0; i < M; i++){
                int temp;
                cin >> temp;
                cout << search_1(temp) << '\n';
        }

        return 0;

}
