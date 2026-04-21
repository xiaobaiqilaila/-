//输入一个n，再输入一串字符串，输出仅包含n种字符的最长子串长度 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10001
int main(){
	int n,len,ans=1,head=0,item=0,hash[256]={0};
	scanf("%d",&n);
	getchar();
	char str[MAX];
	fgets(str,MAX,stdin);
	str[strcspn(str,"\n")]='\0';
	len=strlen(str);
	for(int i=0;i<len;i++){
		hash[(int)str[i]]++;
		if(hash[(int)str[i]]==1){
			item++;
			if(item>n){
				while(item!=n){
					hash[(int)str[head]]--;
					if(hash[(int)str[head]]==0){
						item--;
					}
					head++;
				}
			}
		}
		ans=ans>i-head+1?ans:i-head+1; 
	}
	printf("%d",ans);
	return 0;
}
