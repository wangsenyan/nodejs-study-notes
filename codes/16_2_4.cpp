#include <iostream>
using namespace std;
 
#define N 6
int x[N+1]={0,10,40,60,90,120,140},f[N+1]={0};//f���ڱ��ĳһվ�Ƿ���ͣ�x[i]��ʾ��i������վ������ʼ��ľ���
void Greedy_Select(int x[],int f[])//ѡ������һ������վͣ��
{
	int n=30;//��������ʱ���ܹ��ܵ�Ӣ����
	for(int i=2;i<=N;++i)
	{
		if(x[i]>n)//�����ʼ�㵽ĳ������վ�ľ��������������������ʱ���ܹ��ߵĹ�����������ǰһվ����
		{
			f[i-1]=1;//���ǰһվ��Ҫ����
			n=30;
			n=n+x[i-1];//�ı䵱ǰ�ľ��룬��Ϊ�ڵ�i-1վ�Ѿ��ӹ���
		}
	}
}
 
void Construct_Opitimal_Solution(int x[],int f[])//�����Ҫ����һվ����
{
	for(int i=1;i<=N;++i)
	{
		if(f[i]==1)
			cout<<"The gas station "<<i<<" is chosen! And its distance is "<<x[i]<<endl;
	}
}
 
int main()
{
	Greedy_Select(x,f);
	Construct_Opitimal_Solution(x,f);
	return 0;
}
