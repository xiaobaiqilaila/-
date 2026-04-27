//绝对差固定最短滑动窗口 

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>

int main(){
	int n,delta,*num,minhead=0,maxhead=0,mintail=0,maxtail=0,*maxstack,*minstack,item,ans=INT_MAX;
	scanf("%d%d",&n,&delta);
	num=(int*)malloc(sizeof(int)*n);
	minstack=(int*)malloc(sizeof(int)*n);
	maxstack=(int*)malloc(sizeof(int)*n);
	maxstack[0]=0,minstack[0]=0;
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	for(int i=1;i<n;i++){
		item=num[i];
		while(item>=num[maxstack[maxtail]]){
			maxtail--;
			if(maxtail<0) break;
		}
		maxstack[++maxtail]=i;
		while(item<=num[minstack[mintail]]){
			mintail--;
			if(mintail<0) break;
		}
		minstack[++mintail]=i;
		while(num[maxstack[maxhead]]-num[minstack[minhead]]>delta){
			if(maxstack[maxhead]>minstack[minhead]) minhead++;
			else maxhead++;
		}
		if(num[maxstack[maxhead]]-num[minstack[minhead]]==delta){
			item=abs(maxstack[maxhead]-minstack[minhead])+1+(maxstack[maxhead]==minstack[minhead]);
			ans=ans<item?ans:item;	
			if(maxstack[maxhead]==minstack[minhead]) break;
			if(maxstack[maxhead]>minstack[minhead]) minhead++;
			else maxhead++;
		}
	}
	printf("%d",ans);
	free(num);
	free(maxstack);
	free(minstack);
	return 0;
} 
