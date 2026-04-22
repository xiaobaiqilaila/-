//×îĞ¡¸²¸Ç×Ó´®
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10001

int main(){
	int n,ch,len,hash1[256]={0},hash2[256]={0},item=0,ans=MAX,head=0;
	char str1[MAX],str2[MAX];
	fgets(str1,MAX,stdin);
	str1[strcspn(str1,"\n")]='\0';
	len=strlen(str1);
	fgets(str2,MAX,stdin);
	str2[strcspn(str2,"\n")]='\0';
	n=strlen(str2);
	for(int i=0;i<n;i++){
		hash1[(int)str2[i]]++;
	}
	for(int i=0;i<len;i++){
		ch=(int)str1[i];
		if(hash1[ch]!=0){
			hash2[ch]++;
			if(hash2[ch]<=hash1[ch]) item++;
			while(item==n){
				ch=(int)str1[head];
				if(hash2[ch]!=0){
					hash2[ch]--;
					if(hash1[ch]>hash2[ch]){
						item--;
						ans=ans<i-head+1?ans:i-head+1;
					}
				}
				head++;
			}
		}
	}
	ans=(ans==MAX)?0:ans;
	printf("%d\n",ans);
	return 0;
} 
