#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;


long long base(char *s){
	int n,temp;
	long long max=0;
	n=strlen(s);
	for(int i=0;i<n;i++){
		if(s[i]<='9'){   //单个字符用单引号 
			temp=s[i]-'0';
		}
		else{
			temp=s[i]-'a'+10;
		}
	    if(temp>max)
	    	max=temp;
	}
	return max+1;	
}

long long transfer(char *s,long long k){
	
	long long sum=0,product=1;
	int len=strlen(s);

	while(len){
		if(s[len-1]<='9'){
			sum=sum+(s[len-1]-'0')*product;
		}
		else{
			sum=sum+(s[len-1]-'a'+10)*product;
		}
		product*=k;
		len--;
	}
	return sum;
	
}

int main(){
	
	char a[11],b[11];
	int tag,radix;
	long long ans1,ans2,left,right,mid,r;
	scanf("%s %s %d %d",a,b,&tag,&radix);
	if(tag==2)
		swap(a,b);

	ans1=transfer(a,radix);
	left=base(b);
	right=ans1+1;
	r=ans1+2;
	while(left<=right){//用二分法防止运行超时 
		mid=(right+left)/2;
    	ans2=transfer(b,mid);
    	if(ans1==ans2){
    		r=min(r,mid);
    		right--;
		}
    	else if(ans1<ans2||ans2<0){//ans2的结果可能溢出long long变为负数 
    	    right=mid-1;
    	}
    	else if(ans1>ans2){
    	    left=mid+1;
    	}
	}	
	
	if(r==ans1+2)
		printf("Impossible");
	else
		printf("%lld",r);
		
	return 0;
} 
