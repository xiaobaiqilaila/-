//长度固定的滑动窗口的平均值
//输入n表示数组长，k表示窗口大小，输出滑动过程中每个窗口的平均值 (n>k>0)
#include<stdio.h>
#include<stdlib.h>

int main(){
	int n,k,head,tail,i,*num,*sum;
	scanf("%d%d",&n,&k);
	num=(int*)malloc(sizeof(int)*n);
	sum=(int*)calloc(n-k+1,sizeof(int));
	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	for(i=0;i<k;i++){
		sum[0]+=num[i];
	}
	for(i=1;i<n-k+1;i++){
		sum[i]=sum[i-1]-num[i-1]+num[i-1+k];
	}
	for(i=0;i<n-k+1;i++){
		printf("%.2f\n",((double)sum[i])/k);
	}
	free(num),free(sum);
	return 0;
}
