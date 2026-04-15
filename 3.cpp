//输入字符串，化简为"字符,个数"的形式
//例如： "AAABCCDDDD" → "A3BC2D4"
#include <stdio.h>
#include <string.h>

int main(){
	char str[501],ans[501];
	int valid=0,count=1,j=1;
	scanf("%s",str);
	ans[0]=str[0];
	for(int i=1;i<strlen(str);i++){
		if(str[i]==str[i-1]){
			count++;
		}
		else{
			if(count<2){
				ans[j]=str[i];
				j++;
			}
			else{
				ans[j]=(char)(count+48);
        valid=1;
				count=1;
				ans[j+1]=str[i];
				j+=2;
			}
		}
	}
	if(count>1){
		ans[j]=(char)(count+48),ans[j+1]='\0';
	}
	else{
		ans[j]='\0';
	} 
  if(valid){
    for(int i=0;i<strlen(ans);i++){
		  printf("%c",ans[i]);
	  }
  }
  else{
    printf("NO");
  }
	return 0;
}
