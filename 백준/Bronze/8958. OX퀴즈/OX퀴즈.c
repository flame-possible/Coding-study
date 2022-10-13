#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int num = 0;
	int con = 80;
	char arr[100];
	int ok = 1;
	int result = 0;

	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%s", arr);

		for (int k = 0; arr[k] !=NULL; k++) {
			if (arr[k] == 'O') {
				result += ok;
				ok++;
			}
			else if (arr[k] != 'O') {
				ok = 1;
			}
			
		}
		printf("%d\n", result);
		ok = 1;
		result = 0;
	}
	
	return 0;
}