#include<stdio.h>
#include<string.h>

int main()
{
	int M,e=0,l=0;
	scanf("%d",&M);
	char a[M][20],b[M][20],c[M][20];
	char *early,*last;
	for(int i=0;i<M;i++){
		scanf("%s%s%s",a[i],b[i],c[i]);
	}
	early = b[0];
	last = c[0];
	for(int j=0;j<M;j++){
		if(strcmp(early,b[j])>0){
			early = b[j];
			e = j;
		}
		if(strcmp(c[j],last)>0){
			last = c[j];
			l = j;
		}
	}
	printf("%s %s",a[e],a[l]);
	
}
