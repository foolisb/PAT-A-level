#include<stdio.h>

int main(){
	
	float a[3][3];
	float product=1,max,profit;
	int b[3];
	char s[]={'W','T','L'};
	
	for(int i=0;i<3;i++){
	    max=0;
		for(int j=0;j<3;j++){
			scanf("%f",&a[i][j]);
	        if(a[i][j]>max){
	        	max=a[i][j];
	        	b[i]=j;
			}
		}
	}
	
	for(int n=0;n<3;n++)
		product*=a[n][b[n]];
	
	profit=product*0.65-1;
	
	printf("%c %c %c %.2f",s[b[0]],s[b[1]],s[b[2]],2*profit);	
}
