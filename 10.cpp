/*给定一张初始卡牌，其点数为k，接下来给定一串目标数字串，每次可以进行一次操作
复制一张已有卡牌或使一张卡牌面值变化一点 
输出要进行多少次操作才可以 得到目标数字串。
输入k表示初始卡牌的点数，再输入n表示数字串的长度，随后输入n个数字表示目标数字串*/ 
#include<stdio.h>
#include<stdlib.h>

int qs(const void*a,const void*b){
	return *(const int*)a-*(const int*)b;
}

int main(){
	int n,k,*num,ans=0;
	scanf("%d%d",&k,&n);
	num=(int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	qsort(num,n,sizeof(int),qs);
	if(k>num[n-1]){
		ans=k-num[0]+n-1;
	}
	else if(k<num[0]){
		ans=num[n-1]+n-1;
	}
	else{
		ans=num[n-1]-num[0]+n-1;
	}
	printf("%d\n",ans);
	return 0;
} 
