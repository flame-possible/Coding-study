#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>

int input[1000001] = {0,};
int sorted[1000001] = {0,};
int re_sorted[1000001] = {0,};

int static compare (const void* first, const void* second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

int main(){

        int N;
        scanf(" %d", &N);

        for(int i = 0; i < N; i++){
                scanf(" %d", &input[i]);
        }

        int ans = 0;
        int temp_index = 0;

        int n = 1;

        for(int i = 0; i < N; i++){
                sorted[i] = input[i];
        }


        qsort(sorted, sizeof(int)*N/sizeof(int), sizeof(int), compare);


        re_sorted[0] = sorted[0];
        for(int i = 0; i < N; i++){
                if(sorted[i] != re_sorted[n-1]){
                        re_sorted[n++] = sorted[i];
                }
        }

        for(int i = 0; i < N; i++){
                int left = 0;
                int right = n - 1;
                int mid;
                while(left <= right){
                        mid = (left+right)/2;
                        if(re_sorted[mid] > input[i])
                                right = mid-1;
                        else if(re_sorted[mid] < input[i])
                                left = mid + 1;
                        else
                                break;
                }
                printf("%d ", mid);
        }

        return 0;

}
