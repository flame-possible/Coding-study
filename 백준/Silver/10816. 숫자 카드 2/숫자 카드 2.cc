#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int input[500001] = {0,};
int output[500001][2] = {0,};
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
int search_lower(int n){

        int left = 0;
        int right = N - 1;

        int ans = -1;

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

                        ans = mid;
                        right = mid - 1;
                }
                //cout << left << ' ' << right << '\n';
        }

        return ans;

}

int search_upper(int n){

        int left = 0;
        int right = N - 1;

        int ans = -1;

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

                        ans = mid;
                        left = mid + 1;
                }
                //cout << left << ' ' << right << '\n';
        }

        return ans;

}


int main(){


        cin.tie(NULL);
        cout.tie(NULL);
        ios_base::sync_with_stdio(false);

        cin >> N;

        for(register int i = 0; i < N; i++){

                cin >> input[i];
        }

        sort(input, input + N, compare);

        int M;
        cin >> M;

        int cnt = 0;

        for(register int i = 0; i < M; i++){
                int temp;
                cin >> temp;
                int high = search_upper(temp);
                int low = search_lower(temp);
                if(low == -1){
                        cout << "0\n";
                }
                else{
                        cout << high - low + 1 << '\n';
                }
        }

        return 0;

}
