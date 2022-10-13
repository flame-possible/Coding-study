#include <stdio.h>

int main(){
    register int a, b;
    scanf("%d", &a);
    
    register int result = 0;
    register int cnt = 0;
    for(register int i = 0; i < 100; i++){
        scanf(" %d", &b);
        result += b;
        cnt++;
    }
    printf("%d\n%d\n", cnt, result);
    return 0;
}