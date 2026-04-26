#include<stdio.h>
#include<stdlib.h>

int main(){
	int n,*num,*stack,tail=0,item1,item2,ans=INT_MIN;
	scanf("%d",&n);
	num=(int*)malloc(sizeof(int)*n);
	stack=(int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	stack[0]=0;
	for(int i=1;i<n;i++){
		item1=stack[tail];
		while(num[i]<num[stack[tail]]){
			tail--;
			if(tail<0){
				item2=num[stack[tail+1]]*(item1-tail);
				ans=ans>item2?ans:item2;
				break;
			}
			item2=num[stack[tail+1]]*(item1-stack[tail]);
			ans=ans>item2?ans:item2;
		}
		tail++;
		stack[tail]=i;
	}
	item1=stack[tail];
	while(tail>0){
		item2=num[stack[tail]]*(item1-stack[tail-1]);
		ans=ans>item2?ans:item2;
		tail--;
		if(tail==0){
			item2=num[stack[tail]]*n;
			ans=ans>item2?ans:item2;
		}
	}
	printf("%d\n",ans);
	free(num);
	free(stack);
	return 0;
}
