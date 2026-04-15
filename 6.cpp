/*现在要用一个背包装入一些一定质量一定价值的物品
给定一个变量H表示背包最大载重
随后输入n，表示有n个物品
之后输入n个数字，第i个数字表示第i个物品的质量
再输入n个数字，第i个数字表示第i个物品的价值 
要求输出背包个承载最大价值*/
#include <stdio.h>
#include <stdlib.h>

#define action 2
#if action==1
//二维dp 
int max(int a,int b){
	return a>b?a:b;
}

int main(){
	int count,cap;
	scanf("%d%d",&count,&cap);
	int weight[count],value[count],dp[count+1][cap+1]={0};
	for(int i=0;i<count+1;i++){
		for(int j=0;j<cap+1;j++){
			dp[i][j]=0;
		}
	}
	for(int i=0;i<count;i++){
		scanf("%d",&weight[i]);
	}
	for(int i=0;i<count;i++){
		scanf("%d",&value[i]);
	}
	for(int i=0;i<count;i++){
		for(int j=0;j<cap;j++){
			if(j+1>=weight[i]){
				dp[i+1][j+1]=max(dp[i][j+1],dp[i][j+1-weight[i]]+value[i]);
			}
			else{
				dp[i+1][j+1]=dp[i][j+1];
			}
		}
	}
//	for(int i=0;i<count+1;i++){
//		for(int j=0;j<cap+1;j++){
//			printf("%d ",dp[i][j]);
//		}
//		printf("\n");
//	}
	printf("%d",dp[count][cap]);
	return 0;
}
#endif

#if action==2
//一维滚动数组
int max(int a,int b){
	return a>b?a:b;
}

int main(){
	int count,cap;
	scanf("%d%d",&count,&cap);
	int weight[count],value[count],dp[cap+1]={0};
	for(int i=0;i<count;i++){
		scanf("%d",&weight[i]);
	}
	for(int i=0;i<count;i++){
		scanf("%d",&value[i]);
	}
	for(int i=0;i<count;i++){
		for(int j=cap;j>=0;j--){
			if(j>=weight[i]){
				dp[j]=max(dp[j],dp[j-weight[i]]+value[i]);
			}
		}
	}
	printf("%d",dp[cap]);
	return 0;
}
#endif
