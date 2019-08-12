#include<stdio.h>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;

int N,rate[25]={0};
queue<int> q;

struct record{
	
	char name[23]; //what the fuck.????????????????,?????20????!!!
	int mm,dd,hh,minu;
	char state[10];
	int totaltime;
}re[1010];

bool cmp(record a,record b){
	
	int s=strcmp(a.name,b.name);
	if(s!=0)
		return s<0;              //直接a.name<b.name会只比第一个字母，程序会认为CYLL和CYJJ一样 
	else
		return a.totaltime<b.totaltime;
}

void printbill(char *user){
	
	int fee,fee1,fee2,totalfee=0,totalminu;
	int ontime,offtime,h1,h2,d1,d2,m1,m2;
	int m=(q.size()/2);
	printf("%s %02d\n",user,re[q.front()].mm);
	
	for(int n=0;n<m;n++){
		
		totalminu=0;
		ontime=q.front();q.pop();
		offtime=q.front();q.pop();
		h1=re[ontime].hh;h2=re[offtime].hh;
		d1=re[ontime].dd;d2=re[offtime].dd;
		m1=re[ontime].minu;m2=re[offtime].minu;
	        totalminu=(d2*24*60+h2*60+m2)-(d1*24*60+h1*60+m1);
	        fee1=d1*rate[24]*60+m1*rate[h1];
	        for(int i=0;i<h1;i++)
	    		fee1+=rate[i]*60;
	        fee2=d2*rate[24]*60+m2*rate[h2];
	        for(int j=0;j<h2;j++)
	    		fee2+=rate[j]*60;
	        fee=fee2-fee1;	
		totalfee+=fee;
		printf("%02d:%02d:%02d ",d1,h1,m1);
		printf("%02d:%02d:%02d %d $%.2f\n",d2,h2,m2,totalminu,fee/100.0);
	}
    
	printf("Total amount: $%.2f\n",totalfee/100.0);
}

int main(){
	
	char customer[23];
	
	for(int i=0;i<24;i++){
		
		scanf("%d",&rate[i]);
		rate[24]+=rate[i];
	}
	
	scanf("%d",&N);
	
	for(int j=0;j<N;j++){
		
		scanf("%s",re[j].name);
		scanf("%d:%d:%d:%d",&re[j].mm,&re[j].dd,&re[j].hh,&re[j].minu);
		scanf("%s",re[j].state);
		re[j].totaltime=(re[j].dd-1)*24*60+re[j].hh*60+re[j].minu;
	}
	
	sort(re,re+N,cmp);
	strcpy(customer,re[0].name);

	for(int k=1;k<=N;k++){
	
		if(strcmp(customer,re[k].name)!=0 || k==N){
				
			if(!q.empty())
				printbill(customer);
			if(k==N) break;
			strcpy(customer,re[k].name);
		}
		else{
					
     			if(!strcmp(re[k-1].state,"on-line") && !strcmp(re[k].state,"off-line")){//匹配一次完整通话 

				q.push(k-1);q.push(k);
			}
		}
	}
	
	return 0;
} 
