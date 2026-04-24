#include<stdio.h>
#include<stdlib.h>

int min(int a,int b){
	return a>b?b:a;
}

int main(){
	int m,n,**valuetab,**pathtab;
	scanf("%d%d",&m,&n);
	valuetab=(int**)malloc(sizeof(int*)*m);  
valuetab=（int**）malloc（sizeof（int*）*m）;
	pathtab=(int**)malloc(sizeof(int*)*m);
	for(int i=0;i<m;i++){
		valuetab[i]=(int*)malloc(sizeof(int)*n);
		pathtab[i]=(int*)malloc(sizeof(int)*n);
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&valuetab[i][j]);
		}
	}
	pathtab[0][0]=valuetab[0][0];
	for(int i=1;i<m;i++){
		pathtab[i][0]=pathtab[i-1][0]+valuetab[i][0];
	}
	for(int i=1;i<n;i++){
		pathtab[0][i]=pathtab[0][i-1]+valuetab[0][i];  
pathtab[0][i]=pathtab[0][i-1]+valuetab[0][i];  
pathtab[0][i]=pathtab[0][i-1]+valuetab[0][i];
	}
	for(int i=1;i<m;i++){
		for(int j=1;j<n;j++){
			pathtab[i][j]=min(pathtab[i-1][j],pathtab[i][j-1])+valuetab[i][j];
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%d",pathtab[i][j]);
		}
		printf("\n");
	}
	for(int i=0;i<m;i++){
		free(valuetab[i]);
		free(pathtab[i]);
	}
	free(valuetab);
	free(pathtab);
}
