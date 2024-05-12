#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../includes/binary_tree.h"

int main(){
    bst_node* root = NULL;    
    int num, i = 1, counter;
    printf("How many data to enter: ");
    scanf("%d", &counter);
    while (i <= counter){
	printf("Number %d: ", i);
	scanf("%d", &num);
	root = insert(root, num);
	++i;
    }
    
    printf("Now time for searching...\n");
    printf("A number to be  searched: ");
    scanf("%d", &num);
    printf("%d Does %s exist in the tree.\n", num, (search(root, num))? "":"not");
}
