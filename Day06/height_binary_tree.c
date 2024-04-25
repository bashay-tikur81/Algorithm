#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../includes/binary_tree.h"


void print(void);

int main(){
    bst_node * root;    
    root = NULL;
    int num, i = 1, counter;
    printf("How many data to enter: ");
    scanf("%d", &counter);
    while (i <= counter){
	printf("Data %d: ", i);
	scanf("%d", &num);
	root = insert(root, num);
	++i;
	
    }
    printf("Now time for searching...\n");
    printf("A number to be  searched: ");
    scanf("%d", &num);
    printf("%d Does %s exist in the tree.\n", num, (search(root, num))? "":"not");
    printf("Height of the tree is %d\n", height(root));
    
    printf("\nUsing Iterative function...\n");
    printf("Maximum value: %d\n", max_l(root));
    printf("Minimum value: %d\n", min_l(root));
    printf("\nUsing Recursive function...\n");
    printf("Maximum value: %d\n", max_r(root));
    printf("Minimum value: %d\n", min_r(root));
}

