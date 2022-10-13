#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>

int input[100001][3] = {0,};
int sorted[100001][3] = {0,};

void merge(int left, int mid, int right){
  int i, j, k, l;
  i = left;
  j = mid+1;
  k = left;

  while(i<=mid && j<=right){
    if(input[i][0] < input[j][0]){
      sorted[k][0] = input[i][0];
      sorted[k++][1] = input[i++][1];
    }
    else if(input[i][0] > input[j][0]){
      sorted[k][0] = input[j][0];
      sorted[k++][1] = input[j++][1];

    }
    else{
        if(input[i][1] > input[j][1]){
                sorted[k][0] = input[j][0];
                sorted[k++][1] = input[j++][1];
        }
        else{
                sorted[k][0] = input[i][0];
                sorted[k++][1] = input[i++][1];
        }
    }
  }

  if(i>mid){
    for(l=j; l<=right; l++){
        sorted[k][0] = input[l][0];
        sorted[k++][1] = input[l][1];
    }
  }
  else{
    for(l=i; l<=mid; l++){
        sorted[k][0] = input[l][0];
        sorted[k++][1] = input[l][1];
    }
  }

  for(l=left; l<=right; l++){
        input[l][0] = sorted[l][0];
        input[l][1] = sorted[l][1];
  }
}


void merge_sort( int left, int right){
  int mid;

  if(left<right){
    mid = (left+right)/2;
    merge_sort(left, mid);
    merge_sort(mid+1, right);
    merge(left, mid, right);
  }
}


int main(){

        int N;
        scanf(" %d", &N);

        for(int i = 0; i < N; i++){
                scanf(" %d %d", &input[i][0], &input[i][1]);
        }

        merge_sort(0, N-1);



        for(int i = 0; i < N; i++){

                printf("%d %d\n", input[i][0], input[i][1]);

        }

        return 0;

}
