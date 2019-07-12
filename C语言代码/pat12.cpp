#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

int N,M;
int aver[2000],com[2000],math[2000],engli[2000],quer[2000];
char course[4]={'A','C','M','E'};
bool flag[1000000]={false};

bool cmp(int a,int b){
	
	return a>b;
}

struct stuinfo{
	
	int rank[4],score[4];
	
}stu[1000000];

void ranking(int *r,int *s){
	
	int left=0,right=N-1,mid;
	int p[2000];
	
	for(int i=0;i<4;i++){
    	switch(i){
    		case 0:
    			memcpy(p,aver,sizeof(int)*N);
    			break;
    		case 1:
    			memcpy(p,com,sizeof(int)*N);
    			break;
    		case 2:
    			memcpy(p,math,sizeof(int)*N);
    			break;
    		case 3:
    		 	memcpy(p,engli,sizeof(int)*N);
    		 	break;
    		default:
    			break;
		}
/*		while(left<=right){  //考虑成绩相同的情况下排名问题如1 2 3 3 4而不是1 2 3 3 5，
								二分法容易把第二个3名变成4名，顺序查找又太慢，有时间优化 
		
			mid=(left+right)/2;
	
			if(p[mid]==s[i])
				break;
			else if(p[mid]>s[i]){
				right=mid-1;
			}
			else{
				left=mid+1;
			}
		}*/
		for(int j=0;j<N;j++){
		 
			if(p[j]==s[i]){
	      		r[i]=j+1;
	       	//	printf("%d ",r[i]);
	        	break;
	     	}
	    }
	    // r[i]=find(p,N-1,s[i]);
   }
 
}

int hirank(int *r){
	
	int min=r[0],count=0;
	
	for(int i=0;i<4;i++){
		if(min>r[i]){
			min=r[i];
			count=i;
		}
	}
	
	return count;
}

int main(){
	
	int num,highest;
	scanf("%d %d",&N,&M);
	
	for(int i=0;i<N;i++){
		
		scanf("%d %d %d %d",&num,&com[i],&math[i],&engli[i]);
		flag[num]=true;
		aver[i]=(com[i]+math[i]+engli[i])/3;
		stu[num].score[0]=aver[i];
		stu[num].score[1]=com[i];
		stu[num].score[2]=math[i];
		stu[num].score[3]=engli[i];
		
	}
	
	sort(aver,aver+N,cmp);
	sort(com,com+N,cmp);
	sort(math,math+N,cmp);
	sort(engli,engli+N,cmp);
	
/*	for(int i=0;i<N;i++)
		printf("%d %d %d %d\n",aver[i],com[i],math[i],engli[i]);*/
	
	for(int j=0;j<M;j++){
		
		scanf("%d",&quer[j]);
		
	}
	
	for(int k=0;k<M;k++){
		
		
		if(flag[quer[k]]){
			
			ranking(stu[quer[k]].rank,stu[quer[k]].score);
			highest=hirank(stu[quer[k]].rank);
			printf("%d %c\n",stu[quer[k]].rank[highest],course[highest]);
//            printf("%d %d %d %d\n",stu[quer[k]].rank[0],stu[quer[k]].rank[1],stu[quer[k]].rank[2],stu[quer[k]].rank[3]);			
		}
		else
			printf("N/A\n");
	}
	
	return 0;
} 
