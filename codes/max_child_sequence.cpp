#include<iostream>
using namespace std;
void printSequence(int *b,int* nums,int last);
int main()
{
	int n=8;
	int nums[9]={0,1,7,8,9,2,3,4,5};
	//b�洢��ǰԪ�����ڵ����������е�ǰԪ�ص�ǰһ��Ԫ�����
	//c�洢�Ե�ǰԪ�ؽ�β�ĵ��������г���
	//last�洢��ǰԪ��Ϊֹ������������������е����һ��Ԫ�ص����
	//maxLen�洢��ǰ����������еĳ���
	int b[9]={0},c[9]={0},last[9]={0},maxLen=0;
	c[1]=1,last[1]=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<i;j++)
		{
			if(nums[j]<nums[i] && c[j]+1>c[i])
			{
				c[i]=c[j]+1;
				b[i]=j;
				last[i]=i;
				maxLen=c[i];
			}else if(c[j]>c[i]){
				maxLen=c[j];
				last[i]=last[j];
			}
		}
	}
	cout<<"ԭ���г���Ϊ"<<n<<"�����£�"<<endl;
	for (int i=1;i<=n;i++)
	{
		cout<<nums[i]<<" ";
	}
	cout<<endl<<"����������г���Ϊ"<<maxLen<<"�����£�"<<endl;
	printSequence(b,nums,last[n]);
	cout<<endl;
	return 0;
}
 
void printSequence(int *b,int* nums,int last)
{
	if(b[last]>0)
		printSequence(b,nums,b[last]);
	cout<<nums[last]<<" ";
}
