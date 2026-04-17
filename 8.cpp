//¶àÖØ±³°ü 
#include<stdio.h>
#include<stdlib.h>

#define action 1
#if action==1
int max(int a,int b){
	return a>b?a:b;
}

int square(int base,int exp){
	int result=1;
	for(int i=0;i<exp;i++){
		result*=base;
	}
	return result;
}

int main(){
	int cap,n,w,v;
	scanf("%d%d",&cap,&n);
	int *weight,*value,*count,*dp,remaining;
	weight=(int*)malloc(sizeof(int)*n); 
	value=(int*)malloc(sizeof(int)*n);
	count=(int*)malloc(sizeof(int)*n);
	dp=(int*)calloc((cap+1),sizeof(int));
	int tmp;
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&weight[i],&value[i],&count[i]);
		remaining=count[i];
		for(int exp=0;remaining!=0;exp++){
			tmp=1<<exp;
			if(tmp>remaining) tmp=remaining;
			w=weight[i]*tmp,v=value[i]*tmp;
			for(int j=cap;j>=0;j--){
				if(j>=w){
					dp[j]=max(dp[j],dp[j-w]+v);
				}
			}
			remaining-=tmp;
		}
	}
	printf("%d",dp[cap]);
	free(weight);
	free(value);
	free(dp);
	free(count);
	return 0;
}

#endif

#if action==2

#endif
