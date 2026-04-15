//检测输入字符串（字符个数小于100）是否有重复字符 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define action 1
#if action==0
int qs(const void*a,const void*b){
	return *(char*)a-*(char*)b;
}

int main(int argc, char *argv[])
{
//排序遍历 
  char str[101];
  scanf("%s",str);
  qsort(str,strlen(str),sizeof(char),qs);
  for(int i=1;i<strlen(str);i++){
    if(str[i]==str[i-1]){
    	printf("NO");
    	return 0;
	}
  }
  printf("YES");
  return 0;
}
#endif
#if action==1
int main(){
	//  哈希法 
  char str[101];
  int hash[256]={0};
  scanf("%s",str);
  for(int i=0;i<strlen(str);i++){
  	hash[(int)str[i]]++;
  	if(hash[(int)str[i]]>1){
  		printf("NO");
  		return 0;
	  }
  }
  printf("YES");
  return 0;
}
#endif
#if action==2
#endif
