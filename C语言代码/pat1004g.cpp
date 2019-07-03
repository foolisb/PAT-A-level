#include<stdio.h>
#include<stdlib.h>
#define MAX 100
bool visited[MAX]={false};    //访问标志数组 
int list[100][100],count[100],num[100]={0};
typedef struct EdgeNode  //边表结点   存储边表信息 
{
	int adjvex;		    //邻接点域，存储该顶点对应的下标 
	struct EdgeNode *next;	//链域，指向下一个邻接点 
}EdgeNode;
 
typedef struct VertexNode   //顶点表结点
{
    int data;      //顶点域，存储顶点信息 
	EdgeNode *firstedge;	//边表头指针，指向此顶点的第一个邻接点 
}VertexNode,AdjList[MAX]; 
 
typedef struct
{
	AdjList adjList;     
	int numVertexes,numNonleaf;   //图中当前顶点数和边数 
}GraphAdjList,*GraphAdj;
/*邻接表创建*/
void create(GraphAdj G)
{
	int i,j,k;
	EdgeNode *e;
	for(i=0;i<MAX;i++){
		G->adjList[i].firstedge=NULL;
	}
	for(i=0;i<G->numNonleaf;i++)          //建立顶点表 
	{   
		G->adjList[list[i][0]].data=list[i][0];    //输入顶点的符号 
		G->adjList[list[i][0]].firstedge=NULL; 		//将边表置空 
	}
	for(k=0;k<G->numNonleaf;k++)             //建立边表 
	{
		for(j=1;j<=count[k];j++){
	
		/*使用头插法加入边表结点*/
		e=(EdgeNode *)malloc(sizeof(EdgeNode));   //生成结点 
 
		e->adjvex=list[k][j];
		e->next=G->adjList[list[k][0]].firstedge;
		G->adjList[list[k][0]].firstedge=e;
	    }
	} 
} 
/*邻接表的深度优先递归*/
void DFS(GraphAdj G,int i,int d)
{
	EdgeNode *p;
	visited[i]=true;         		//访问过了该顶点，标记为TRUE 
	p=G->adjList[i].firstedge;     //让p指向边表第一个结点 
	while(p)                      //在边表内遍历 
	{
	
		if(!visited[p->adjvex])    //对未访问的邻接顶点递归调用 
			DFS(G,p->adjvex,d+1); 
		if(!G->adjList[p->adjvex].firstedge)
			num[d+1]++;   
		p=p->next;
	}
 } 
 
int main()
{
	GraphAdjList G;
    int deep=1,j,i;
	scanf("%d%d",&G.numVertexes,&G.numNonleaf);
	for(int i=0;i<G.numNonleaf;i++){
		scanf("%d%d",&list[i][0],&count[i]);
			for(int j=1;j<=count[i];j++)
				scanf("%d",&list[i][j]);
	}
	create(&G);
	DFS(&G,1,deep);
	for(j=99;j>0;j--){
		if(num[j]!=0){
			deep=j;
			break;
		}
		if(j==1&&num[j]==0){
		    num[1]=1;
			deep=1;
		}
	}
	for(i=1;i<=deep;i++){
	     if(i==deep)
	    	printf("%d",num[i]);
	     else 
		    printf("%d ",num[i]); 
		} 
	return 0;	 
 } 

