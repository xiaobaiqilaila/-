/*春春是一名道路工程师，负责铺设一条长度为 n的道路。
铺设道路的主要工作是填平下陷的地表。整段道路可以看作是n块首尾相连的区域，
第 i块区域下陷的深度为di。
春春每天可以选择一段连续区间 [L,R]
填充这段区间中的每块区域，让其下陷深度减少 1。
在选择区间时，需要保证，区间内的每块区域在填充前下陷深度均不为 0 。
春春希望你能帮他设计一种方案，可以在最短的时间内将整段道路的下陷深度都变为0。*/
#include<stdio.h>
#include<stdlib.h>

int main(){
	int n,item=0,ans=0,*num,*stack,min,head=0,tail=0;
	scanf("%d",&n);
	num=(int*)malloc(n*sizeof(int));
	stack=(int*)calloc(n,sizeof(int));
	scanf("%d",&num[0]);
	min=num[0];
	for(int i=1;i<n;i++){
		scanf("%d",&num[i]);
		min=min<num[i]?min:num[i];
	}
	stack[0]=0;
	for(int i=0;i<n;i++){
		while(num[stack[head]]<=num[i]&&i<n) stack[head]=i++;
		while(num[stack[tail]]>num[i]&&i<n) stack[++tail]=i++;
		ans+=num[stack[head]]-num[stack[tail]];
		item=num[stack[tail]];
		min=min>item?min:item;
		tail=0,stack[tail]=i;
	}
	ans+=min;
	if(num[stack[tail]]>num[stack[tail]-1]) ans+=(num[stack[tail]]-item);
	printf("%d\n",ans);
    return 0;
}
