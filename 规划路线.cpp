/*给定一个n*n的二维数组表，从左上角出发，只能向右或者向下移动，输出所有路径中，所经过的数字的和*/ 

#include<stdio.h>
#include<stdlib.h>

int main(){
	int n; 
	printf("请输入表格边长：");
	scanf("%d",&n);
	int **tab;
	tab=(int**)malloc(sizeof(int*)*n);
	for(int i=0;i<n;i++){
		tab[i]=(int*)malloc(sizeof(int)*n);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			tab[i][j]=0;
			printf("%d ",tab[i][j]);
		}
		printf("\n");
	}
	printf("请输入表格中数字（从左往右，从上到下）：\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("i:%d j:%d\n",i,j);
			scanf("%d",&tab[i][j]);
		}
	}
//	for(int i=0;i<n;i++){
//		for(int j=0;j<n;j++){
//			printf("%d ",tab[i][j]);
//		}
//		printf("\n");
//	}
	
} 
