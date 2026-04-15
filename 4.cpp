#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  char str[101];
  fgets(str,100,stdin);
  str[strcspn(str,"\n")]='\0';//fgets函数会将回车与空格都读入，所以需要把末行的回车符替换为‘\0’ 
  for(int i=0;i<strlen(str);i++){
    printf("%c",str[i]); 
  }
  return 0;
}
