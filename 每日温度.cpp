//√ø»’Œ¬∂»
#include<stdio.h>
#include<stdlib.h>

int main(){
	int n,*temp,*stack,*ans,tail=0;
	scanf("%d",&n);
	temp=(int*)malloc(sizeof(int)*n);
	stack=(int*)malloc(sizeof(int)*n);
	ans=(int*)calloc(n,sizeof(int));
	for(int i=0;i<n;i++){
		scanf("%d",&temp[i]);
	}
	stack[0]=0;
	for(int i=1;i<n;i++){
		while(tail>=0&&temp[i]>temp[stack[tail]]){
			ans[stack[tail]]=i-stack[tail];
			tail--;
		}
		tail++,stack[tail]=i;
	}
	for(int i=0;i<n;i++){
		printf("%d\n",ans[i]);
	}
	free(temp);
	free(stack);
	free(ans);
	return 0;
}
