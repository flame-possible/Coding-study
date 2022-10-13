#include <iostream>

using namespace std;

int input[1000] = {0,};

void quickSort(int first, int last)
{
	int pivot;
	int i;
	int j;
	int temp;
	
	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;

		while (i < j)
		{
			while (input[i] <= input[pivot] && i < last)
			{
				i++;
			}
			while (input[j] > input[pivot])
			{
				j--;
			}
			if (i < j)
			{
				temp = input[i];
				input[i] = input[j];
				input[j] = temp;
			}
		}

		temp = input[pivot];
		input[pivot] = input[j];
		input[j] = temp;

		quickSort(first, j - 1);
		quickSort(j + 1, last);
	}
}

int main(){

	int N;
	cin >> N;

	for(register int i = 0; i < N; i++){
		cin >> input[i];
	}

	quickSort(0, N - 1);

	int temp = input[0];
	int result = input[0];

	for(register int i = 1; i < N; i++){
		temp += input[i];
		result += temp;
	}

	cout << result << '\n';

	return 0;
}