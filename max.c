#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int MergeCount,QuickCount;
int main() {
    //生成随机数
    int n,buf,BubbleCount,i,j;
    printf("请输入想要生成的随机数的个数：");
    scanf("%d",&n);
    int a[n],b[n],c[n];
    srand((unsigned)time(NULL)); //设置随机数种子
    for (i= 0; i< n; i++) {
	a[i]= (rand() % 100) + 1 ;//rand()产生的是一个很大的数，对其求余就可以达到限定范围的目的
    printf("%d ", a[i]);
    }
    for(i=0;i<n;i++)
    {
        b[i]=a[i];
        c[i]=a[i];
    }
    //冒泡排序算法
    printf("\n-------冒泡排序算法------");
     for (i=0; i<n-1; ++i)  //比较n-1轮
    {
        for (j=0; j<n-1-i; ++j)  //每轮比较n-1-i次,
        {
            BubbleCount++;
            if (b[j] >b[j+1])
            {
                buf = b[j];
                b[j] = b[j+1];
                b[j+1] = buf;
            }
        }
    }
    printf("\n冒泡排序后的结果为：");
    for (i=0; i<n; ++i)
    {
        printf("%d ", b[i]);
    }
    printf("\n冒泡排序比较的次数为：%d",BubbleCount);
    printf("\n-------合并排序算法------");
    merge_sort(a,0,n-1);
    printf("\n合并排序后的结果为：");
    for (i=0; i<n; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n合并排序比较的次数为：%d",MergeCount);
    printf("\n-------快速排序算法------");
    sort(c,0,n-1);
    printf("\n快速排序后的结果为：");
    for (i=0; i<n; ++i)
    {
        printf("%d ", c[i]);
    }
    printf("\n快速排序比较的次数为：%d",QuickCount);

    return 0;
}

void merge(int arr[], int low, int mid, int high){
    int i, k;
    int *tmp = (int *)malloc((high-low+1)*sizeof(int));
    //申请空间，使其大小为两个
    int left_low = low;
    int left_high = mid;
    int right_low = mid + 1;
    int right_high = high;
    for(k=0; left_low<=left_high && right_low<=right_high; k++){
        MergeCount++;// 比较两个指针所指向的元素
        if(arr[left_low]<=arr[right_low]){
            tmp[k] = arr[left_low++];
        }else{
            tmp[k] = arr[right_low++];
        }
    }
    if(left_low <= left_high){  //若第一个序列有剩余，直接复制出来粘到合并序列尾
    //memcpy(tmp+k, arr+left_low, (left_high-left_low+l)*sizeof(int));
    for(i=left_low;i<=left_high;i++)
        tmp[k++] = arr[i];
    }
    if(right_low <= right_high){
    //若第二个序列有剩余，直接复制出来粘到合并序列尾
    //memcpy(tmp+k, arr+right_low, (right_high-right_low+1)*sizeof(int));
        for(i=right_low; i<=right_high; i++)
            tmp[k++] = arr[i];
    }
    for(i=0; i<high-low+1; i++)
        arr[low+i] = tmp[i];
    free(tmp);
    return;
}
void merge_sort(int arr[], unsigned int first, unsigned int last){
    int mid = 0;
    if(first<last){
        mid = (first+last)/2;
        merge_sort(arr, first, mid);
        merge_sort(arr, mid+1,last);
        merge(arr,first,mid,last);
    }
    return;
}
void sort(int a[],int left ,int right)
{
    int i,j,temp;
    i=left;
    j=right;
    temp=a[left];
    if(left>right) return;
    while(i!=j)                       //i不等于j时，进行循环
    {
        QuickCount++;
        while(a[j]>=temp&&j>i)
            j--;
        if(j>i)
            a[i++]=a[j];
        while(a[i]<=temp&&j>i)
            i++;
        if(j>i)
            a[j--]=a[i];
    }
    a[i]=temp;
    sort(a,left,i-1);     //对小于基准元素部分进行快速排序
    sort(a,i+1,right);    //对大于基准元素部分进行快速排序
}
