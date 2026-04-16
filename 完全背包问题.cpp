//完全背包
#include<stdio.h>
#include<stdlib.h>

int max(int a,int b){
	return a>b?a:b;
}

int main(){
	int cap,count;
	scanf("%d%d",&cap,&count);
	int *weight,*value,*dp;
	weight=(int*)malloc(sizeof(int)*count); 
	value=(int*)malloc(sizeof(int)*count);
	dp=(int*)calloc((cap+1),sizeof(int));
	for(int i=0;i<count;i++) scanf("%d",&weight[i]);
	for(int i=0;i<count;i++) scanf("%d",&value[i]);
	for(int i=0;i<count;i++){
		for(int j=1;j<=cap;j++){
			if(j>=weight[i]){
				dp[j]=max(dp[j],dp[j-weight[i]]+value[i]);
			}
		}
	}
	printf("%d",dp[cap]);
	free(weight);
	free(value);
	free(dp);
}
