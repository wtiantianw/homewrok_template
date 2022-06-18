#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int m[3000][3000];//前i个物品装入容量为j的背包中获得的最大价值
int begintime,endtime;

int max(int a,int b)
{
    if(a>=b)
        return a;
    else return b;
}

int KnapsackDP(int n,int weight[],int value[],int C)
{

    //填表,其中第一行和第一列全为0,即 V(i,0)=V(0,j)=0；
    for(int i=0; i<=n; i++)
        m[i][0]=0;
    for(int j=0; j<=C; j++)
        m[0][j]=0;
    //用到的矩阵部分V[n][C] ,下面输出中并不输出 第1行和第1列

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=C; j++)
        {
            if(j<weight[i-1])   //包的容量比该商品体积小，装不下，此时的价值与前i-1个的价值是一样的
            {
                m[i][j]=m[i-1][j];
            }
            else   //还有足够的容量可以装该商品，但装了也不一定达到当前最优价值，所以在装与不装之间选择最优的一个
            {
                m[i][j]=max(m[i-1][j],m[i-1][j-weight[i-1]]+value[i-1]);
            }
        }
    }

    return m[n][C];

}

void Judge(int C,int n,int weight[]) 	//判断哪些物品被选中
{
    int j=C;
    int *state=(int *)malloc(n*sizeof(int));

    for(int i=n; i>=1; i--)
    {
        if(m[i][j]>m[i-1][j])   //如果装了就标记，然后减去相应容量
        {
            state[i]=1;
            j=j-weight[i-1];
        }
        else
            state[i]=0;
    }
    printf("选中的物品是:");
    for(int i=1; i<=n; i++)
        if(state[i]==1)
            printf("%d ",i);
    printf("\n");
}

int main()
{

    int n;        //物品数量
    int Capacity;//背包最大容量

    time_t t;
    struct tm * lt;
    time (&t);//获取Unix时间戳。
    lt = localtime (&t);//转为时间结构。


    for(int i=0;i<=3;i++)
    {
        printf("请输入背包的最大容量:");
    scanf("%d",&Capacity);

    printf("输入物品数:");
    scanf("%d",&n);
    begintime=clock();	//计时开始

    int *weight=(int *)malloc(n*sizeof(int));//物品的重量
    int *value=(int *)malloc(n*sizeof(int)); //物品的价值


    printf("以下是随机生成的物品的重量:");
    for (int i= 0; i< n; i++)
    {
        weight[i]= (rand() % Capacity) + 1 ;//rand()产生的是一个很大的数，对其求余就可以达到限定范围的目的
        printf("%d ", weight[i]);
    }
    printf("\n");

    printf("以下是随机生成的物品的价值:");
    for (int i= 0; i< n; i++)
    {
        value[i]= (rand() % 100) + 1 ;//rand()产生的是一个很大的数，对其求余就可以达到限定范围的目的
        printf("%d ", value[i]);
    }
    printf("\n");


    int s=KnapsackDP(n,weight,value,Capacity);  //获得的最大价值

    Judge(Capacity,n,weight);  //判断那些物品被选择

    printf("最大物品价值为: ");
    printf("%d\n",s);
    endtime = clock();	//计时结束
    printf("Running Time：%dms\n", endtime-begintime);
    time (&t);//获取Unix时间戳。
    lt = localtime (&t);//转为时间结构。
    }



    return 0;
}
