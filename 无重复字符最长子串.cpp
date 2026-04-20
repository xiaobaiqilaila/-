//无重复字符最长子串
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10001
#define action 2
#if action==1
int main(){
	int n,hash[256]={0},head=0,ans=1;
	char str[MAX];
	fgets(str,MAX,stdin);
	str[strcspn(str,"\n")]='\0';
	n=strlen(str);
	for(int i=0;i<n;i++){
		if(hash[(int)str[i]]==0){
			hash[(int)str[i]]++;
			ans=i-head+1>ans?i-head+1:ans;
		}
		else{
			hash[str[head]]--,head++,i--;
		}
	}
	printf("%d\n",ans);
	return 0;
} 
#endif
#if action==2
int main(){
	int n,hash[256]={0},head=0,ans=1;
	char str[MAX];
	fgets(str,MAX,stdin);
	str[strcspn(str,"\n")]='\0';
	n=strlen(str);
	for(int i=0;i<n;i++){
		hash[(int)str[i]]++;
		while(hash[(int)str[i]]>1){
			hash[(int)str[head]]--,head++;
		}
		ans=ans>i-head+1?ans:i-head+1;
	}
	printf("%d\n",ans);
	return 0;
} 

#endif
