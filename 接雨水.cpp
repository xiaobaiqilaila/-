//接雨水
#include<stdio.h>
#include<stdlib.h>
#define get(a) printf("%d\n",a)
#define action 2

#if action==1
int main(){
	int n,*num,*item,maxindex=0,ans=0;
	scanf("%d",&n);
	num=(int*)malloc(sizeof(int)*n);
	item=(int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
		maxindex=num[maxindex]>num[i]?maxindex:i;
	}
	item[0]=num[0],item[n-1]=num[n-1];
	for(int i=1;i<=maxindex;i++){
		item[i]=item[i-1]>num[i]?item[i-1]:num[i];
		ans+=(item[i]-num[i]);
	}
	for(int i=n-2;i>maxindex;i--){
		item[i]=item[i+1]>num[i]?item[i+1]:num[i];
		ans+=(item[i]-num[i]);
	}
	printf("%d",ans);
	free(num);
	free(item);
	return 0;
}
#endif

#if action==2
int min(int a,int b){
	return a<b?a:b;
}
int main(){
	int n,*num,*stack,tail=0,ans=0;
	scanf("%d",&n);
	num=(int*)malloc(sizeof(int)*n);
	stack=(int*)malloc(sizeof(int)*n);
	stack[0]=0;
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	for(int i=1;i<n;i++){
		while(num[i]>num[stack[tail]]){
			tail--;
			if (tail<0) break;
			ans+=(min(num[i],num[stack[tail]])-num[stack[tail+1]])*(i-stack[tail]-1);
		}
		stack[++tail]=i;
	}
	printf("%d",ans);
	free(num);
	free(stack);
	return 0;
}
#endif
