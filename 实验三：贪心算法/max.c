#include <stdio.h>
#define N 100        
#include<time.h>
int nType;                 
int SelectNumber;        
float MaxValue;        
float TotalWeight;        
float LimitWeight;        
int begintime,endtime;
struct  goods       
{
    int order;         
    float weight;         
    float value;        
    float UnitValue;         
}good[N];
void CheckOut(struct goods g[] ,int num,float tw)   
{
    int i;
    SelectNumber=0;
    TotalWeight=0.0;
    MaxValue=0.0;
    for(i=0;i<num;i++)
        if(TotalWeight+g[i].weight <=tw )   /*从已排序的物品中选出一个物品，测试增加一个物品后是否超过限重*/
        {
            MaxValue+=g[i].value;
            TotalWeight=TotalWeight+g[i].weight;
            SelectNumber++;
        }
        else   /*一旦超重则停止对后面物品的选择，退出循环，结束函数执行*/
            break;
}
void sort(struct goods g[] ,int num)                  /*对所有物品单位重量价值按降序排列*/
{
    float temp,max;
    int i,j,flag,position,temporder;
    for(i=0;i<num-1;i++)
    {   max=g[i].UnitValue;
        flag=0;
        for(j=i+1;j<num;j++)
            if(max<g[j].UnitValue)
            {   position=j;
                max=g[j].UnitValue;
                flag=1;
            }
        if(flag)
        {   temp=g[i].UnitValue;                     /*交换单位重量价值*/
            g[i].UnitValue=max;
            g[position].UnitValue=temp;
            temp=g[i].value;                       /*交换价值*/
            g[i].value=g[position].value;
            g[position].value=temp;
            temp=g[i].weight;                      /*交换重量*/
            g[i].weight=g[position].weight;
            g[position].weight=temp;
            temporder=g[i].order;                   /*交换序号*/
            g[i].order=g[position].order;
            g[position].order=temporder;
        }
    }
}
int main()
{
    int i;
    time_t t;
    struct tm * lt;
    time (&t);//获取Unix时间戳。
    lt = localtime (&t);//转为时间结构。

    printf("请输入物品类别个数:");
    scanf("%d",&nType);
    printf("请输入背包限重的重量:");
    scanf("%f",&LimitWeight);
    begintime=clock();	//计时开始
    printf("\n随机生成各物品的重量和价值:\n");
    for(i=0;i<nType;++i)
    {
        good[i].weight= (rand() % 100) + 1 ;
        good[i].value= (rand() % 100) + 1 ;
        good[i].UnitValue=good[i].value/good[i].weight;
        good[i].order=i;
    }
    printf("\n输入的物品有：\n");
    printf("序号  重量    价值\n");
    for(i=0;i<nType;i++)
        printf("%3d   %.2f   %.2f\n",good[i].order+1,good[i].weight,good[i].value);
    sort(good,nType);                          /*对物品按单位重量价值降序排列*/
    CheckOut(good,nType,LimitWeight);               /*调用选择物品函数*/
    printf("\n被选中的物品有：\n");
    printf("序号  重量    价值\n");
    for(i=0;i<SelectNumber;i++)
        printf("%3d   %.2f   %.2f\n",good[i].order+1,good[i].weight,good[i].value);
    printf("合计总价值为: %f\n",MaxValue);
    endtime = clock();	//计时结束
    printf("Running Time：%dms\n", endtime-begintime);
    time (&t);//获取Unix时间戳。
    lt = localtime (&t);//转为时间结构。
}
