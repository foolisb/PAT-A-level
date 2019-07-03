#include<stdio.h>
#include<string.h>

char number[][10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
//在函数体外不要用char *numbe[],函数体内用char *a[],a[] = number[]可以对a[]赋值 

int main(){
	char s[101] = {};
	int a[10] = {0};//一定给数组指定大小，赋初值不然各种错误 
	int k,n,m = 0,sum = 0;
    scanf("%s",s);
	n = strlen(s);//s[]一定要给定大小再用 strlen()函数，不然出错 
	for(int i = 0;i < n;i++){
		sum += (s[i] - '0');
	}
	while(1){
		k = sum % 10;
		a[m] = k;
		printf("%d",a[m]);
		sum /= 10;
		m++;
	    if(sum == 0)
			break;	
	}
	m--;
	printf("%s",number[a[0]]);
	for(int j = m;j >= 0;j--){
        if(j == 0)
            printf("%s",number[a[j]]);
        else
            printf("%s ",number[a[j]]); 
    }
		
}
 
