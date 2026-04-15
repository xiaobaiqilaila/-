//输入两个字符串，后者是前者的连续或非连续子集，且前者只比后者多一个字符，要求输出该字符 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define action 2
#if action==0
//哈希 
int main(int argc, char *argv[])
{
  char str1[101],str2[101];
  int hash1[256]={0},hash2[256]={0};
  scanf("%s",str1); 
  scanf("%s",str2);
  for(int i=0;i<strlen(str1);i++){
  	hash1[(int)str1[i]]++;
  }
  for(int i=0;i<strlen(str2);i++){
  	hash2[(int)str2[i]]++;
  }
  for(int i=0;i<256;i++){
  	if(hash1[i]!=hash2[i]){
  		printf("%c",(char)i);
	  }
  }
  return 0;
}
#endif
#if action==1
//排序 
int qs(const void *a,const void *b){
	return *(const char*)a -*(const char*)b;
}
int main(int argc, char *argv[])
{
  char str1[101],str2[101];
  scanf("%s",str1); 
  scanf("%s",str2);
  qsort(str1,strlen(str1),sizeof(char),qs);
  qsort(str2,strlen(str2),sizeof(char),qs);
  for(int i=0;i<strlen(str1);i++){
  	if(str1[i]!=str2[i]){
  		printf("%c",str1[i]);
  		return 0;
	  }
  }
  return 0;
}
#endif
#if action==2
//异或运算
char find(char *s, char *t) {
    char result = 0;
    for (int i = 0; s[i]; i++) result ^= s[i];
    for (int i = 0; t[i]; i++) result ^= t[i];
    return result;
}
int main(int argc, char *argv[])
{
  char str1[101],str2[101];
  scanf("%s",str1); 
  scanf("%s",str2);
  printf("%c",find(str1,str2));
  return 0;
}
#endif
