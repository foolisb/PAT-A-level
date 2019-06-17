#include<stdio.h>
#include<stdlib.h>
#define MAX 100
bool visited[MAX]={false};    //���ʱ�־���� 
int list[100][100],count[100],num[100]={0};
typedef struct EdgeNode  //�߱���   �洢�߱���Ϣ 
{
	int adjvex;		    //�ڽӵ��򣬴洢�ö����Ӧ���±� 
	struct EdgeNode *next;	//����ָ����һ���ڽӵ� 
}EdgeNode;
 
typedef struct VertexNode   //�������
{
    int data;      //�����򣬴洢������Ϣ 
	EdgeNode *firstedge;	//�߱�ͷָ�룬ָ��˶���ĵ�һ���ڽӵ� 
}VertexNode,AdjList[MAX]; 
 
typedef struct
{
	AdjList adjList;     
	int numVertexes,numNonleaf;   //ͼ�е�ǰ�������ͱ��� 
}GraphAdjList,*GraphAdj;
/*�ڽӱ���*/
void create(GraphAdj G)
{
	int i,j,k;
	EdgeNode *e;
	for(i=0;i<MAX;i++){
		G->adjList[i].firstedge=NULL;
	}
	for(i=0;i<G->numNonleaf;i++)          //��������� 
	{   
		G->adjList[list[i][0]].data=list[i][0];    //���붥��ķ��� 
		G->adjList[list[i][0]].firstedge=NULL; 		//���߱��ÿ� 
	}
	for(k=0;k<G->numNonleaf;k++)             //�����߱� 
	{
		for(j=1;j<=count[k];j++){
	
		/*ʹ��ͷ�巨����߱���*/
		e=(EdgeNode *)malloc(sizeof(EdgeNode));   //���ɽ�� 
 
		e->adjvex=list[k][j];
		e->next=G->adjList[list[k][0]].firstedge;
		G->adjList[list[k][0]].firstedge=e;
	    }
	} 
} 
/*�ڽӱ��������ȵݹ�*/
void DFS(GraphAdj G,int i,int d)
{
	EdgeNode *p;
	visited[i]=true;         		//���ʹ��˸ö��㣬���ΪTRUE 
	p=G->adjList[i].firstedge;     //��pָ��߱��һ����� 
	while(p)                      //�ڱ߱��ڱ��� 
	{
	
		if(!visited[p->adjvex])    //��δ���ʵ��ڽӶ���ݹ���� 
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

