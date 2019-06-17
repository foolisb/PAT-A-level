#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;

int leaf[100] = {0};
bool visit[100] = {false}; 
typedef struct arcnode{
	
	int adjvex;
	arcnode *nextarc;
}arcnode;

typedef struct {
	int data;
	arcnode *firstnode;
}vnode;

typedef struct{
	
	vnode adjlist[100];
	
}Agraph;

void Dfs(Agraph G,int v){
	
    arcnode *p;
	visit[v] = true;
	printf("%d",v);
	p = G.adjlist[v].firstnode;
    while(p != NULL){
		if(visit[p->adjvex] == false)
	    	Dfs(G,p->adjvex);
		    p = p->nextarc;	
	}
}

int main(){
	
	Agraph Q;
	arcnode *q;
	int deep = 1,n,m;
	//Q = (Agraph*)malloc(sizeof(Agraph));
	scanf("%d %d",&n,&m);
	for(int i = 0;i < m;i++){
		int k,num;
		scanf("%d %d",&num,&k);
		q = (arcnode*)malloc(sizeof(arcnode));
	    Q.adjlist[num].firstnode = q;
	    Q.adjlist[num].firstnode->nextarc = NULL; //不能对要访问的指针赋值NULL 
	    Q.adjlist[num].firstnode->adjvex = NULL;
		for(int j = 0;j < k;j++){
			q = (arcnode*)malloc(sizeof(arcnode));
			scanf("%d",&q->adjvex);
	        q->nextarc = Q.adjlist[num].firstnode;
	        Q.adjlist[num].firstnode = q;
		}
		
	}
    Dfs(Q,1);
 //   printf("%d\n",Q.adjlist[1].firstnode->nextarc->nextarc->adjvex);
//    printf("%d",visit[Q.adjlist[2].firstnode->adjvex]);
/*	for(int i = 1;i < deep;i++){
	    if(i == deep - 1){
	    	printf("%d",leaf[i]);
		}
		else
			printf("%d ",leaf[i]);
    } */
	return 0;
	
}
