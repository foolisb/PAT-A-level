#include<stdio.h>
//#include<algorithm> 
//using namespace std;
const int max=10000;
int a[max],d[max],o[max];
int main(){
	int n,original=0,k=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	d[0]=a[0];
	o[0]=0;
	for(int j=1;j<n;j++){
		if((d[j-1] + a[j]) > a[j]){
			d[j]=d[j-1] + a[j];
			o[j]=original;
		}
		else{
			d[j]=a[j];
			o[j]=original=j;
		}
	}
	for(int i=1;i<n;i++){
		if(d[i]>d[k])
			k=i;
	}
	if(d[k]>=0){
		printf("%d %d %d",d[k],a[o[k]],a[k]); 
	}
	else{
		printf("%d %d %d",0,a[0],a[n-1]);
	}
}
