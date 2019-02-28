
//#include "StdAfx.h"
#include <iostream>  
#include <vector>
using namespace std;  
 
void change(vector<int>c,vector<int>&m,vector<int>&s,int n)
{
	int k = c.size()-1;//��������
	m[0] = 0;
	for(int i=1;i<=n;i++)
	{
		m[i] = INT_MAX;
		for(int j=1;j<=k && (i>=c[j]);j++)
		{
			if(m[i-c[j]]+1< m[i])
			{
				m[i] = m[i-c[j]]+1; 
				s[i] = j;
			}
		}
	}
}
 
void print(vector<int>c,vector<int>s,int n,int count)
{
	int k = c.size();
	vector<int>number(k);
	for(int i=1;i<k;i++)
		number[i] = 0;
	while(n != 0)
	{
		number[s[n]] ++;
		n = n - c[s[n]];
	}
	printf("��%d��Ӳ�ң�\n",count);
	for(int i=k-1;i>=1;i--)
	{
		if(number[i] > 0)
			printf("%d��%d��Ӳ��  ",number[i],c[i]);
	}
	cout<<endl;
}
int main()
{
	//const int c1[] = {0,1,5,10,25};//��Ǯ���� ��һ��Ԫ��0���������� �����±괦��
	const int c1[] = {0,1,3,7,11};
	int k = sizeof(c1)/sizeof(int);
	int n = 21;//��������Ǯ��
	vector<int>c;
	for(int i=0;i<k;i++)
		c.push_back(c1[i]);
	vector<int>m(n+1);//��ͬ��Ǯ����Ӧ����СӲ����
	vector<int>s(n+1);//��¼��ѡӲ�� 
	change(c,m,s,n);
	print(c,s,n,m[n]);
}

