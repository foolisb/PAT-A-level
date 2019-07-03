#include<stdio.h>

struct term{
	int ex;
	float co;
}a[10],b[10]; 

int main(){
	
	int k1,k2,num=0,p[20]={0},tem;
	float ans[2001]={0},q[20]={0};
	scanf("%d",&k1);
	for(int i=0;i<k1;i++){
		scanf("%d %f",&a[i].ex,&a[i].co);
	}
	scanf("%d",&k2);
	for(int j=0;j<k2;j++){
		scanf("%d %f",&b[j].ex,&b[j].co);
	}
	for(int i=0;i<k1;i++){
		for(int j=0;j<k2;j++){

			tem=a[i].ex+b[j].ex;
			ans[tem]+=(a[i].co*b[j].co); 
 	    }
	}
 	for(int n=2000;n>=0;n--){
 		if(ans[n]!=0.0){
 //			p[num]=n;
 //           q[num]=ans[n];
 			num++;
		 }
	 }
	printf("%d",num);
    for(int k=2000;k>=0;k--)
        if(ans[k])
            printf(" %d %.1f",k,ans[k]);    //缺点改用数组p，q时第3个测试点总是错误？？？？以后解决
		 
    return 0;
}
