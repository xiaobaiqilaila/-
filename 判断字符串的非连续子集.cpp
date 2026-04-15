//输入两个字符串（字符个数均少于100）检测前者的若干个字符能否排列得到后者 
#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

int qs(const void*a,const void *b){
	return *(const char*)a-*(const char*)b;
}

int main(){
	//哈希 
	char str1[101],str2[101];
	int hash1[256]={0},hash2[256]={0};//比赛编译器可能不会初始化 
	scanf("%s",str1);
	scanf("%s",str2);
	if(strlen(str1)<strlen(str2)){
		printf("NO");
		return 0;
	}
	for(int i=0;i<strlen(str1);i++){
		hash1[(int)str1[i]]++;
	}
	for(int i=0;i<strlen(str2);i++){
		hash2[(int)str2[i]]++;
		if(hash2[(int)str2[i]]>hash1[(int)str2[i]]){
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
	 
} 
