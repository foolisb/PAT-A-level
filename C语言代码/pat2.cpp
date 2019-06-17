//注意系数相加等于0的情况，要删除该项
//声明的变量类型与输入的格式化匹配，%d不能赋值给float变量 
#include<stdio.h>
struct Dot{
	int ex;
	float co;
	bool f;
};
int main( )
{
	int i = 0;
	struct Dot bn[1001];
	int q,k1,k2,count = 0;	
	float p;	
	for(i = 0;i < 1001;i++)
		   {
		      bn[i].f = false;
	          bn[i].co = 0;
		   }
	scanf("%d",&k1);
		for(i = 1;i <= k1;i++){
			scanf("%d",&q);
			bn[q].ex = q;
			scanf("%f",&p);
			bn[q].co += p;
		}
	scanf("%d",&k2);
		for(i = 1;i <= k2;i++){
			scanf("%d",&q);
			bn[q].ex = q;
			scanf("%f",&p);
			bn[q].co += p;
		}
	for(i = 0;i <= 1000;i++)
	{
         if(bn[i].co != 0){
         	bn[i].f = true;
         	count++;
		 }
	}
	printf("%d",count);
 
	for(i = 1000;i >= 0;i--)
	{
		if(bn[i].f == true){
			printf(" %d %.1f",bn[i].ex,bn[i].co);
		}
	}
	
	
}
