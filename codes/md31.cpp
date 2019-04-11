
#include <iostream>
#include <math.h>
using namespace std;
//λ����ĳ˷�
int bit_Multiplication(int a,int b)
{
     int ans=0;
	 for (int i=1;i;i<<=1,a<<=1)
	 {
		 if (b&i)
		 {
			 ans+=a;
		 }
	 }
	 return ans;
}
//λ����ĳ���
int bit_Division1(int x,int y)
{
    int ans=0;
	for (int i=31;i>=0;i--)
	{   
		if ((x>>i)>=y)
		{
			ans+=(1<<i);
			x-=(y<<i);
		}
	}
	return ans;
}
//���������Ķ�����λ��
int bit_num(int d)
{
   int i=0;
   while (d)
   {
	   d>>=1;
	   i++;
   }
   return i;
}
//λ����ĳ��� ������
int bit_Division2_quotient(int x,int y)
{
	int c2=bit_num(x),c1=bit_num(y),quotient=0;
	for (int i=c2-c1;i>=0;i--)//i=c2-c1��ֹ����y��λ�󳬹��޷����������ֵ ʱ�临�Ӷ�O(c2-c1)
	{
		unsigned int a=(y<<i);//����i=c2-c1��֤��y<<i������� a��c1+c2-c1=c2λ
		if (a<=x)
		{
			quotient+=(1<<i);
			x-=a;
		}
	}
	//�ܵ�ʱ�临�Ӷ�Ϊ O(c2)=O(x�Ķ�����λ��)=O(b^2) bΪ������ʮ����λ��
	return quotient;
}
//λ����ĳ��� �������� �������һ����ֻ�Ƿ���ֵ��ͬ
int bit_Division2_Remainder(int x,int y)
{
	int c2=bit_num(x),c1=bit_num(y),quotient=0;
	for (int i=c2-c1;i>=0;i--)//i=c2-c1��ֹ����y��λ�󳬹��޷����������ֵ ʱ�临�Ӷ�O(c2-c1)
	{   
		unsigned int a=(y<<i);//����i=c2-c1��֤��y<<i������� a��c1+c2-c1=c2λ
		cout<<i<<'\t'<<a<<'\t'<<x<<endl;
		if (a<=x)
		{
			//quotient+=(1<<i);
			x-=a;
		}
	}
	//�ܵ�ʱ�临�Ӷ�Ϊ O(c2)=O(x�Ķ�����λ��)=O(b^2) bΪ������ʮ����λ��
	return x;
}
int main()
{
	cout<<bit_Multiplication(789,43)<<endl;
	cout<<bit_Division1(789,43)<<endl;
	cout<<"�̣�"<<bit_Division2_quotient(350,43)<<endl;
	cout<<"������"<<bit_Division2_Remainder(789,43)<<endl;
	return 0;
}
//int main()
//{
//    long long  n;
//	int flag=1;
//    cout<<"enter:"<<endl;
//    cin>>n;
//	//O(��nlgn)
//    for (int i=2;i<=sqrt(n);i++)//O(a=��n)
//	{
//		int m=n,k=0;
//		while (m%i==0)//O(k=lgn)
//		{
//			m=m/i;
//			k++;
//		}
//		if (m==1&&k>1)
//		{
//			cout<<n<<"�Ƿ�ƽ����,����һ������"<<i<<"����"<<k<<"����="<<n<<endl;
//			flag=0;
//			break;
//		}
//	}
//	if (flag)
//	{
//		cout<<"n="<<n<<"�����ڷ�ƽ����"<<endl;
//	}
//	return 0;
//}

