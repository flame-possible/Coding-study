#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<cursor.h>
//#include<conio.h>

int main()
{
	int check = 0;
	char* bak = (char*)malloc(sizeof(char) * 1000001);
	char nok = 0;
	
	fgets(bak, 1000001, stdin);
	//scanf(" %[^\n]s", bak);
	for (int i = 0; i < 1000001; i++) {
		if (bak[i] == 10) {
			break;
		}
		else if (bak[i] == 32 && bak[i + 1] == 10) {
			break;
		}
		else if (bak[i] == 32) {
			check++;	
		}
	}
	if (bak[0] == 32 && bak[1] == 10) {
		printf("0");
	}
	else if (bak[0] == 32) {
		printf("%d", check);
	}
	else
	{
		printf("%d", check+1);
	}

	free(bak);
	return 0;
}