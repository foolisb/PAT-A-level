#include<stdio.h>
#include<string.h>

char number[][10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
//�ں������ⲻҪ��char *numbe[],����������char *a[],a[] = number[]���Զ�a[]��ֵ 

int main(){
	char s[101] = {};
	int a[10] = {0};//һ��������ָ����С������ֵ��Ȼ���ִ��� 
	int k,n,m = 0,sum = 0;
    scanf("%s",s);
	n = strlen(s);//s[]һ��Ҫ������С���� strlen()��������Ȼ���� 
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
 
