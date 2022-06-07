#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 
int main() {
    int n;
    printf("请输入一个数字：");
    scanf("%d",&n);
    srand((unsigned)time(NULL)); //设置随机数种子
    for (int i= 0; i< n; i++) {
	n = (rand() % 10) + 1 ;//产生1~10的随机数
    //rand()产生的是一个很大的数，对其求余就可以达到限定范围的目的
    printf("%d ", n);
}
    return 0;
}