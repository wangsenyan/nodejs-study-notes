#include <stdio.h>
#include <stdlib.h>
 
 //ÿ����Ʒ�ļ�ֵ������
 typedef struct goods_t
  {
   int weight;
   int value;
  }goods;
 
 //��̬�滮
 int dp(goods* data, const int n, const int weight)
 {
   int A[n+1][weight+1];
   int i,j;
   //���i=0����w=0
   for (i = 0; i < n+1; i++)
     A[i][0] = 0;
   for (i = 0; i < weight+1; i++)
     A[0][i] = 0;
   int w;
   for (i = 1; i <= n; i++)
   {
     for (w = 1; w <= weight; w++)
     {
       if (data[i-1].weight > w)
    A[i][w] = A[i-1][w];
      else
       {
     A[i][w] = A[i-1][w] > (data[i-1].value + A[i-1][w-data[i-1].weight]) ? A[i-1][w] : (data[i-1].value + A[i-1][w-data[i-1].weight]);
       }
     }
   }
   for(i=0;i<=weight;i++)
      printf("%d ",i);
   for(i=0;i<=n;i++){
   	 for(j=0;j<=weight;j++)
       printf("%d ",A[i][j]);
     printf("\n");
   }
    
     
      
   return A[n][weight];
 }
 
 int main()
 {
   //�����������
   int max_weight;
   scanf("%d", &max_weight);
   //������Ʒ�������������ͼ�ֵ
   int num;
   scanf("%d", &num);
   int n = num;
   goods* data = (goods*)malloc(n*sizeof(goods));
 
   goods g;
   while (num--)
   {
    scanf("%d%d", &(g.weight), &(g.value));
     data[n-num-1] = g;
   }
   printf("%d\n", dp(data, n, max_weight));
   return 0;
 }
