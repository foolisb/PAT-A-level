#include<stdio.h>
#include<math.h>
int cal(int k){
	int time=0;
	if(k>0){
		time = k*6+5;
    }
	else
	{
		time = abs(k)*4+5;
	}
	
	return time;
}
int main(){
	int n,a[100],sum=5,k;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sum += 6*a[0];
	for(int j=1;j<n;j++){
		k=a[j]-a[j-1];
		sum += cal(k);
	}
	printf("%d",sum);
}
