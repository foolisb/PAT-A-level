#include<stdio.h>
#include<math.h>

const int max=10000;

bool isPrime(int n){
	
	if (n<=1) return false;
	int sqr=(int)sqrt(1.0*n); //sqr是向下取整得数所以不用考虑2和3，必定返回true 
	for(int i=2;i<=sqr;i++){  //sqrt函数要求参数为浮点数，包含在math头文件下 
		
		if(n%i==0) return false;
	}
	
	return true;
}

int revernumber(int num,int r){
	
	int z[40],size=0,sum=0,p=1;
	
	do{
		
		z[size++]=num%r;
		num/=r;
	}while(num);
	
	for(int i=size-1;i>=0;i--){
		
		sum+=(z[i]*p);
		p*=r;
	}
	
	return sum;
}

int main(){
	
	int number[max],radix[max],renumber[max];
	int N,D,length;
	
	for(int i=0;;i++){
		
		scanf("%d",&N);
		if(N<0){
			length=i;
			break;
		}
		scanf("%d",&D);
		number[i]=N;radix[i]=D;
	}
	
	for(int j=0;j<length;j++)
		renumber[j]=revernumber(number[j],radix[j]);
	
	for(int k=0;k<length;k++){
		
		if(isPrime(renumber[k])&&isPrime(number[k]))
			printf("Yes\n");
		else
			printf("No\n");
	}
	
	return 0;
}
