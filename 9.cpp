#include <stdio.h>
#include <stdlib.h>

int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	int *num,*queue,head=0,tail=0;
	num=(int*)malloc(sizeof(int)*n);
	queue=(int*)calloc(n,sizeof(int));
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
    for(int i=0;i<n;i++){
    	while(tail>=head&&num[queue[tail]]>=num[i]){
    		tail--;
		}
		tail++,queue[tail]=i;
		if(i-queue[head]==k){
			head++;
		}
		if(i>k-2){
			printf("%d",num[queue[head]]);
		}
	}
	free(queue);
    return 0;
}
