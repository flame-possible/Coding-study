#include <stdio.h>

int main(void) {
  int input;
  int tenth;
  int first;
  int add;
  int new_num = -1;
  int input_save = 0;
  int tries = 0;

  scanf("%d", &input);

  input_save = input;
   while(new_num != input_save){
     tenth = input/10;
     first = input % 10;
     add = (tenth+first) % 10;
     new_num = (first*10) + add;
     input = new_num;
     tries++;
   }
   printf("%d\n", tries);
  return 0;
}
