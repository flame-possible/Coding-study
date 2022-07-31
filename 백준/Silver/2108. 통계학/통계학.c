#include <stdio.h>
int main(){
	int sum = 0,midi = 0,i,n,num,maxi,max = -4000,min = 4000,count = 0,countn=0,maxmax = 0;
	int number[8001]={0,};
	scanf("%d",&n);
	int mid = n/2+1;
	for(i = 0 ; i < n;i++){
		scanf("%d",&num);
		if(min>num) min = num;
		if(max<num) max = num;//<------------여기가 원래 else if문이었습니다.
        //입력이 만약 1\n 0 이라면 min값만 0으로 바뀌어서 max값이 바뀌지 않아 틀렸던 것 이였습니다.
        //그래서 또한번 if 문으로 max값을 바꿀 수 있게 만들었습니다.
		number[4000+num]++;
		sum +=num;
	}
	for(i = 0 ; i < 8001 ; i++){
		if(maxmax<number[i]){
			maxmax = number[i];//최빈 값을 찾음 
		}
	}
	for(i = 0 ;i  < 8001 ;i++){
		if(number[i] == maxmax){//최빈 값들이 여러가지 일 경우를 생각해 또 나옴 2번째 것을 찾기 위함  
			count++;
			maxi = i;//1차 최빈 값의 값 
		}
		if(count == 2){//2차 최빈 값의 값 
			maxi = i;
			break;
		}
	}
	
	for(i = 0 ; i <8001 ; i++){
		countn+=number[i];
		if(countn>=mid) {
			midi = i-4000;
			break;
		}
	}
	
	
	
	
	
	if(((double)sum/(double)n) > -1&&(double)sum/(double)n<0) {
		printf("0\n");
	}
	else printf("%1.f\n",(double)sum/(double)n);
	printf("%d\n",midi);
	printf("%d\n",maxi-4000);
	printf("%d",max-min);
	
	return 0;
}