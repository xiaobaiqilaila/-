//Ω””ÍÀÆ
#include<stdio.h>
#include<stdlib.h>

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
