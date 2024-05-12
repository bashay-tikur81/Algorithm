#include<stdio.h>


int main(){
    int row = 3,column = 4;
    int twoD[row][column];

    // read values from console
    int i,j;
    for(i = 0;i<row;i++){
	for(j = 0;j<column;j++){
	    printf("Enter values at [%d,%d]:",i,j);
	    scanf("%d",&twoD[i][j]);
	}
    }
    // Writing to console
    for(int k = 0; k< row; k++){
	printf("|");
	for(int m = 0; m < column; m++)
	    printf("%d%c",twoD[k][m],(m+1<column)? ',':'|');
	printf("\n");
    }
}
