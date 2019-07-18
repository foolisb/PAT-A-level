#include<stdio.h>

const int max=1001;//必须加const，后面才能用 
int father[max],check[max];
int map[max*max][2];//并查集的建立，max*max因为相同的路a->b和

int findfather(int x){                //b->a可以输两次 
	
	if(x==father[x]) return x;
	else return findfather(father[x]);//不用递归内存降一半 
	
}

void Union(int x,int y){
	
	x=findfather(x);
	y=findfather(y);
	if(x==y)return;
	else father[y]=x;
}

int main(){
	
	int N,M,K,ocity,count=-1;
	
	scanf("%d %d %d",&N,&M,&K);

	for(int j=0;j<M;j++)
		scanf("%d %d",&map[j][0],&map[j][1]);
		
	for(int k=0;k<K;k++)
		scanf("%d",&check[k]);
	
	for(int k=0;k<K;k++){
		
		ocity=check[k];
		count=-1;
		
		for(int i=1;i<=N;i++)
			father[i]=i;
			
		for(int m=0;m<M;m++){
			
			if(map[m][0]!=ocity&&map[m][1]!=ocity)
				Union(map[m][0],map[m][1]);
		}
			
		for(int n=1;n<=N;n++){
		
			if(father[n]==n&&n!=ocity)
				count++;
		}
		
		printf("%d\n",count);
	}
	
	return 0;
} 
