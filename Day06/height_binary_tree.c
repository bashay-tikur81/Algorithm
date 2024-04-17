#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define true 1
#define false 0

typedef struct bst_node {
    int data;
    struct bst_node *left;
    struct bst_node *right;
} bst_node;

void print(void);
int max_r(bst_node*);
int max_l(bst_node*);
int min_r(bst_node*);
int min_l(bst_node*);
int maximum(int, int);
int height(bst_node*);
bst_node* give_me_node(int);
bst_node* insert(bst_node*, int);
int search(bst_node *, int);

bst_node *root;

int main(){
    int num, i = 1, counter;
    root = NULL;
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
    

    print();

}
void print(){

    printf("\nUsing Iterative function...\n");
    printf("Maximum value: %d\n", max_l(root));
    printf("Minimum value: %d\n", min_l(root));
    printf("\nUsing Recursive function...\n");
    printf("Maximum value: %d\n", max_r(root));
    printf("Minimum value: %d\n", min_r(root));
    
}

bst_node* insert(bst_node *root, int data){
    if (root == NULL){
	root = give_me_node(data);
    }
    else if (data <= root->data){
	root->left = insert(root->left, data);
    }
    else {
	root->right = insert(root->right, data);
    }
    return root;
}

int search(bst_node* root, int data){
    if (root == NULL){
	return false;
    }
    if (root->data == data){
	return true;
    }
    else if (data <= root->data){
	return search(root->left, data);
    }
    else {
	return search(root->right, data);
    }
}
bst_node* give_me_node(int value){
    bst_node* new_node = (bst_node*) malloc(sizeof(bst_node));
    if (new_node == NULL){
	printf("Can't allocate memory.\n");
	exit(1);
    }
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

int min_l(bst_node *root){
    if (root == NULL){
	printf("No value at the tree (-_-)");
	return -1;
    }
    while(root->left != NULL){
	root = root->left;
    }
    return root->data;
}
int max_l(bst_node *root){
    if (root == NULL){
	printf("No value at the tree (-_-)");
	return -1;
    }
    while (root->right != NULL){
	root = root->right;
    }
    return root->data;
}
// finding minimum using recursive function

int min_r(bst_node * root){
    if (root == NULL){
	printf("No value at the tree.\n");
	return -1;
    }
    else if (root->left == NULL){
	return root->data;
    }
    return min_r(root->left);
}

int max_r(bst_node * root){
    if (root == NULL){
	printf("No value at the tree.\n");
	return -1;
    }
    else if (root->right == NULL){
	return root->data;
    }
    return max_r(root->right);
}

int height(bst_node* root){
    int left_height, right_height;
    if (root == NULL){
	return -1;
    }

    left_height = height(root->left);
    right_height = height(root->right);
    return maximum(left_height, right_height) + 1;

}
int maximum(int a, int b){
    return (a >= b)?a:b;
}
