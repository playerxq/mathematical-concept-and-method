#include "stdafx.h"
#include<iostream> //����������   ���ƹ�ʽh(n)=h(n-1)*(4*n-2)/(n-1)
using namespace std;
#include<string.h>
#define N 100  //��һ���������������鳤��
#define M 10000 //��4λ���浽 �����е�һ������
int a[101][N]={0};
void multiply(int a[],int n,int b)//�����˷�
{
    int i,aa=0;
    for(i=N-1;i>=0;i--)
    {
        aa=aa+b*a[i];
        a[i]=aa%M;
        aa=aa/M;
    }
}
void divide(int a[],int n,int b)//��������
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
    a[1][N-1]=1;        //��ʼ����һ������n=1ʱ
    for(i=2;i<101;i++)
    {
        memcpy(a[i],a[i-1],N*sizeof(int));//
        multiply(a[i],N,4*i-2);//ִ�г�(4*n-2)  h(n)=h(n-1)*(4*n-2)
        divide(a[i],N,i+1);        //ִ��/(n+1)
    }
    while(scanf("%d",&n)!=EOF&&n!=-1)
    {
        for(i=0;i<N&&a[n][i]==0;i++);//ȥ������ǰ��Ϊ0��Ԫ��
        printf("%d",a[n][i++]);//�����Ϊ0�ĵ�һ��Ԫ��
        for(i=i;i<N;i++)//��������
        printf("%04d",a[n][i]);//ע��Ҫ�õ�"%04d",����Ϊ4λ����ǰ�油0
        printf("\n");
    }
    return 0;
}