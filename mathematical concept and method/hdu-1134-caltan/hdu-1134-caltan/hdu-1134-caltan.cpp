#include "stdafx.h"
#include<iostream> //卡特兰数求法   递推公式h(n)=h(n-1)*(4*n-2)/(n-1)
using namespace std;
#include<string.h>
#define N 100  //存一个卡特兰数的数组长度
#define M 10000 //以4位数存到 数组中的一个数中
int a[101][N]={0};
void multiply(int a[],int n,int b)//大数乘法
{
    int i,aa=0;
    for(i=N-1;i>=0;i--)
    {
        aa=aa+b*a[i];
        a[i]=aa%M;
        aa=aa/M;
    }
}
void divide(int a[],int n,int b)//大数除法
{
    int div=0,i;
    for(i=0;i<N;i++)
    {
        div=div*M+a[i];
        a[i]=div/b;
        div=div%b;
    }
}
int main()
{
    int n,i;
    memset(a[1],0,sizeof(a[1]));//
    a[1][N-1]=1;        //初始化第一个即当n=1时
    for(i=2;i<101;i++)
    {
        memcpy(a[i],a[i-1],N*sizeof(int));//
        multiply(a[i],N,4*i-2);//执行乘(4*n-2)  h(n)=h(n-1)*(4*n-2)
        divide(a[i],N,i+1);        //执行/(n+1)
    }
    while(scanf("%d",&n)!=EOF&&n!=-1)
    {
        for(i=0;i<N&&a[n][i]==0;i++);//去掉数组前面为0的元素
        printf("%d",a[n][i++]);//输出不为0的第一个元素
        for(i=i;i<N;i++)//输出后面的
        printf("%04d",a[n][i]);//注意要用到"%04d",若不为4位数，前面补0
        printf("\n");
    }
    return 0;
}