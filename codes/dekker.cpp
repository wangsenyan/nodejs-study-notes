#include<iostream>
//Dekker�㷨
bool flag[2];//�ṩ���н��̵�״̬
int turn;//��ʾ�ĸ�����Ӧ��ֽ���
void p0()
{
	while(true)
	{
		flag[0]=true;//P0��ʹ���ٽ���
		while(flag[1])//P1Ҳ��ʹ��
			if(turn==1)//ȷʵ�ֵ���P1ʹ��
			{
				flag[0]=false;//P0ȡ������
				while(turn==1)
					/*ʲôҲ����*/
				flag[0]=true;//P1�����P0������������
			}
			//�ٽ���
			flag[0]=false;//p0������
			turn=1;//��Ȩ���ƽ���P1
			//���ಿ��
	}
}
void p1()
{
	while(true)
	{
		flag[1]=true;
		while(flag[0])
			if(turn==0)
		{
			flag[1]=false;
			while(turn==0)
				/*ʲôҲ����*/
			flag[1]=true;	
		}
		flag[1]=fasle;
		turn=0;
	}
}
void main()
{
	turn=0;
	flag[0]=false;
	flag[1]=false;
	perbegin(p0(),p1());
	return 0;
}
