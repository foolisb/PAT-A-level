#include<stdio.h>
#include<queue>
#include<string.h>
 
using namespace std;

const int maxn=1001;
const int INF=0x3fffffff;
int N,M,K,Q;//��������ÿ����������������������ͻ�����������ѯ�ͻ����
int transaction[maxn],transactionb[maxn],query[maxn],usingtime[maxn],accutime[21]={0};

void timetransform(int totaltime,int num){
	
	int HH=8,MM=0,h;
	
	h=totaltime/60;
	MM=totaltime%60;
	HH+=h;
	
	if((totaltime-transactionb[num])>=540)//����ʼʱ�䲻������17:00��֮ǰ��ʼ����Ĳ��ܼ��㶼Ҫ������ 
		printf("Sorry\n");
	else{
		printf("%02d:%02d\n",HH,MM);
	}

}

int main(){
	
	int number,customer,min;
	queue<int> q[21];
	
	scanf("%d %d %d %d",&N,&M,&K,&Q);
	
	for(int i=1;i<=K;i++)
		scanf("%d",&transaction[i]);
		
	for(int n=1;n<=Q;n++)
		scanf("%d",&query[n]); 
	
	memcpy(transactionb,transaction,sizeof(transaction));
	//K<=N*M����K>=N*M
	if(K<=N*M){
	
		for(int j=1;j<=K;j++){
		
		    number=(j-1)%N+1;
			q[number].push(j);
		}
		
		for(int k=1;k<=K;k++){
			
			number=(k-1)%N+1;
			//customer=q[number].pop();pop() ����void 
			customer=q[number].front();
			q[number].pop();
			accutime[number]+=transaction[customer];
			usingtime[customer]=accutime[number];
		}
		
	}
	else{
		
		for(int j=1;j<=N*M;j++){
			
			number=(j-1)%N+1;
			q[number].push(j);
		}
		
		for(int k=(N*M+1);k<=K;k++){
			
			min=INF;
			for(int m=1;m<=N;m++){
				
				if(min>transaction[q[m].front()]){
					
					min=transaction[q[m].front()];
					number=m;
				}
			}
			
			for(int l=1;l<=N;l++){
				
				transaction[q[l].front()]-=min;
				accutime[l]+=min;
			}
			
			customer=q[number].front();
			q[number].pop();q[number].push(k);
			usingtime[customer]=accutime[number];
		}
		
		for(int n=1;n<=N*M;n++){
			
			number=(n-1)%N+1;
			customer=q[number].front();
			q[number].pop();
			accutime[number]+=transaction[customer];
			usingtime[customer]=accutime[number];
		}
		
	}
	
	for(int i=1;i<=Q;i++)
		timetransform(usingtime[query[i]],query[i]);
		
	return 0;
}
