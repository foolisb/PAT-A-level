#include<stdio.h>
#include<queue>
#include<math.h>
#include<algorithm>
using namespace std;

struct record{
	
	int hh,mm,ss,totaltime;
	int ptime,stime,ltime;
}re[10010];

bool cmp(record x,record y){
	
	return x.totaltime<y.totaltime;
}

int main(){
	
	int N,K,start=8*3600,close=17*3600,anumber=0,wtime=0;

	scanf("%d %d",&N,&K);
	queue<int> q[K];
	
	for(int i=0;i<N;i++){
	
		scanf("%d:%d:%d %d",&re[i].hh,&re[i].mm,&re[i].ss,&re[i].ptime);
		re[i].stime=re[i].totaltime=re[i].hh*60*60+re[i].mm*60+re[i].ss;
	}
	
	sort(re,re+N,cmp);
	
	for(int n=0;n<N;n++){
		
		if(n<K){
	
			q[n].push(n);
			if(re[n].stime<start){
					
				anumber++;
				wtime+=(start-re[n].stime);
				re[n].ltime=start+re[n].ptime*60;
			}
			else if(re[n].stime<close){
					
				anumber++;
				re[n].ltime=re[n].stime+re[n].ptime*60;
			}
			else 
				break;
		}	
		else{

			int mtime=-10000000,k;
			if(re[n].stime>=close) 
				break;
			else{
				
				anumber++;
				for(int p=0;p<K;p++){
					
					if(mtime<(re[n].stime-re[q[p].front()].ltime)){
						
						k=p;mtime=re[n].stime-re[q[p].front()].ltime;
					}
                }
                if(mtime<0){ 
                
				    wtime+=abs(mtime);
					re[n].ltime=re[q[k].front()].ltime+re[n].ptime*60;
				} 
				else
					re[n].ltime=re[n].stime+re[n].ptime*60;
				q[k].pop();q[k].push(n);
			}
		}
	}
	 
	if(anumber)
		printf("%.1f",wtime/60.0/anumber);
	else
		printf("0.0");
	return 0;
}
